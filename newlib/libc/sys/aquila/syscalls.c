#include <sys/types.h>
#include <errno.h>

#include "syscalls.h"

char **environ;

int aquila_auth(uid_t uid, const char *pw)
{
    int ret;
    SYSCALL2(ret, SYS_AUTH, uid, pw);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}
