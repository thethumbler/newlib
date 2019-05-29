#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#include "syscalls.h"

pid_t waitpid(pid_t pid, int *stat_loc, int options)
{
    pid_t ret;
    SYSCALL3(ret, SYS_WAITPID, pid, stat_loc, options);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

pid_t wait(int *stat_loc)
{
    return waitpid(-1, stat_loc, 0);
}

