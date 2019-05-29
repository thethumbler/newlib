#include <errno.h>
#include <stdarg.h>
#include <sys/ioctl.h>

#include "syscalls.h"

static int __ioctl(int fildes, int request, void *argp)
{
    int ret;
    SYSCALL3(ret, SYS_IOCTL, fildes, request, argp);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

int ioctl(int fildes, int request, ...)
{
    va_list ap;
    va_start(ap, request);
    void *argp = va_arg(ap, void *);
    va_end(ap);

    return __ioctl(fildes, request, argp);
}

