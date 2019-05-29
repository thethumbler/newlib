#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>

#include "syscalls.h"

int fcntl(int fildes, int cmd, ...)
{
    va_list ap;
    va_start(ap, cmd);
    void *arg = va_arg(ap, void *); /* FIXME */
    va_end(ap);

    int ret;
    SYSCALL3(ret, SYS_FCNTL, fildes, cmd, arg);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}


int open(const char *path, int oflags, ...)
{
    int ret, mode = 0;

    if (oflags & O_CREAT) {
        va_list ap;
        va_start(ap, oflags);
        mode = va_arg(ap, int);
        va_end(ap);
    }

    SYSCALL3(ret, SYS_OPEN, path, oflags, mode);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

int mknod(const char *path, mode_t mode, dev_t dev)
{
    int ret;
    SYSCALL3(ret, SYS_MKNOD, path, mode, dev);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

