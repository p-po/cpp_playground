#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <dlfcn.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

char buf[512];
size_t min_alloc_size = 1024 * 1024;

char memblock[8*1024];

void* ( *realmalloc )( size_t size );
void* ( *realcalloc )( size_t nmemb, size_t size );
void* ( *realrealloc )( void* ptr, size_t size );
void ( *realfree )( void* ptr );

static bool initProgress = false;

__attribute__( ( constructor ) ) void HookInitialize()
{
        static bool initialized = false;

        initProgress = true;

        if( !initialized )
        {
            if( !realmalloc ) realmalloc = ( void* ( * ) ( size_t ) ) dlsym( RTLD_NEXT, "malloc" );
            if( !realcalloc ) realcalloc = ( void* ( * ) ( size_t, size_t ) ) dlsym( RTLD_NEXT, "calloc" );
            if( !realrealloc ) realrealloc = ( void* ( * ) ( void*, size_t ) ) dlsym( RTLD_NEXT, "realloc" );
            if( !realfree ) realfree = ( void ( * )( void* ) ) dlsym( RTLD_NEXT, "free" );

            if( !realmalloc || !realcalloc || !realrealloc || !realfree ) exit(1);
        }

        char *p = getenv("ALLOC_SIZE");
        if (p) min_alloc_size = atoi(p);

        initialized = true;
        initProgress = false;
}

void* malloc(size_t len)
{
    HookInitialize();

    if (len >= min_alloc_size) {
        snprintf(buf, sizeof buf, "malloc: requested size: %zu\n", len);
        write(1, buf, strlen(buf));
    }
    void* ret = ( *realmalloc )( len );
    return ret;
}

void* calloc( size_t nmemb, size_t size )
{
    if (initProgress) return memblock;

    HookInitialize();
    if (nmemb * size >= min_alloc_size) {
        snprintf(buf, sizeof buf, "calloc: requested size: %zu\n", nmemb * size);
        write(1, buf, strlen(buf));
    }
    void* ret = ( *realcalloc )( nmemb, size );
    return ret;
}

void* realloc( void* ptr, size_t size )
{
    HookInitialize();

    if (size >= min_alloc_size) {
        snprintf(buf, sizeof buf, "realloc: requested size: %zu\n", size);
        write(1, buf, strlen(buf));
    }

    void* ret = ( *realrealloc )( ptr, size );
    return ret;
}

void free(void *ptr)
{
    if (ptr == memblock) return;
    realfree(ptr);
}
