// Monitor changes in a directory and print free space

#include <iostream>
#include <thread>
#include <string>
#include <cstdalign>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>

#include <boost/filesystem.hpp>

using namespace std;

uintmax_t get_available_space(string& dir)
{
    using namespace boost::filesystem;
    space_info si = space(dir);
    return si.available;
}


void monitor(string dir = "")
{
    int length, i = 0, wd;
    int fd = inotify_init();
    if (fd < 0) {
        return;
    }

    const char *tmp = ::getenv("MONITOR_DIR");
    string dir_ = tmp ? tmp : "/tmp";

    uintmax_t init_size = get_available_space(dir_);

    cout << "Initial dir_ size: " << init_size << endl;

    while (1)
    {
        char buf[sizeof (struct inotify_event) * 100] __attribute__ ((aligned(__alignof__(struct inotify_event)))) = {};

        wd = inotify_add_watch(fd, &dir_[0], IN_CREATE | IN_MODIFY);
        length = ::read(fd, buf, sizeof buf);

        /*checking for error*/
        if (length < 0) {
            perror("read");
        }

        struct inotify_event *event = (struct inotify_event *) buf;

        if (event->len && ((event->mask & IN_CREATE) || (event->mask & IN_MODIFY))) {
            cout << "Dir free space after create/modify event: " << get_available_space(dir_) << endl;
        }
    }

    inotify_rm_watch(fd, wd);

    ::close(fd);
}

int main()
{
    std::thread t(monitor, "");
    t.detach();
    pthread_exit(0);
}
