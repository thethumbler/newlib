#include <sys/select.h>
#include <errno.h>

#include "syscalls.h"

struct select_args {
    int nfds;
    fd_set *readfds;
    fd_set *writefds;
    fd_set *exceptfds;
    struct timeval *timeout;
};

int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout)
{
    struct select_args args = {
        nfds,
        readfds,
        writefds,
        exceptfds,
        timeout
    };

    int ret;
    SYSCALL1(ret, SYS_SELECT, &args);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

