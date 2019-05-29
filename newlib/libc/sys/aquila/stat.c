#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#include "syscalls.h"

mode_t umask(mode_t mask)
{
    SYSCALL1(mask, SYS_UMASK, mask);
    return mask;
}

int chmod(const char *path, mode_t mode)
{
    int ret;
    SYSCALL2(ret, SYS_CHMOD, path, mode);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int mkdir(const char *path, mode_t mode)
{
    int ret;
    SYSCALL2(ret, SYS_MKDIR, path, mode);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}
