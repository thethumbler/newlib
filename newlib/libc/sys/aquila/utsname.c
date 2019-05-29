#include <sys/utsname.h>
#include <errno.h>

#include "syscalls.h"

int uname(struct utsname *name)
{
    int ret;
    SYSCALL1(ret, SYS_UNAME, name);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

