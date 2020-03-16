#include <iostream>
#include <thread>
#include <cinttypes>
#include <unistd.h>
#include <typeinfo>
#include <fcntl.h>

using namespace std;

void f()
{
    ::sleep(20);
}

int main()
{

#ifdef THREAD_CREATE
    auto start = std::chrono::system_clock::now();
    std::thread t(f);
    auto end = std::chrono::system_clock::now();
    std::cout<< "Thread creation time:" << (std::chrono::duration_cast<std::chrono::microseconds> (end - start).count()) << endl;
    t.join();
#else
    ::sleep(20);
#endif
}
