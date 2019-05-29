#include <sys/mount.h>
#include <errno.h>

#include "syscalls.h"

int mount(const char *type, const char *dir, int flags, void *data)
{
    struct mount_args {
        const char *type;
        const char *dir;
        int flags;
        void *data;
    } __attribute__((packed)) args = {
        type, dir, flags, data
    };

    int ret;
    SYSCALL1(ret, SYS_MOUNT, &args);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

