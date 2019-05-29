#include <sys/types.h>
#include <signal.h>
#include <errno.h>

#include "syscalls.h"

int killpg(int pgrp, int sig)
{
    return kill(-pgrp, sig);
}

int sigsuspend(const sigset_t *mask)
{
    errno = -ENOSYS;
    return -1;
}

int sigprocmask(int how, const sigset_t *set, sigset_t *oldset)
{
    int ret;
    SYSCALL3(ret, SYS_SIGMASK, how, set, oldset);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int kill(pid_t pid, int sig)
{
    int ret;
    SYSCALL2(ret, SYS_KILL, pid, sig);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

int sigaction(int sig, const struct sigaction *act, struct sigaction *oact)
{
    int ret;
    SYSCALL3(ret, SYS_SIGACT, sig, act, oact);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

typedef void (*sighandler_t)(int);
sighandler_t signal(int sig, sighandler_t handler)
{
    struct sigaction act  = {0}, oact = {0};

    act.sa_handler = handler;
    int ret = sigaction(sig, &act, &oact);

    if (ret != -1) {
        return oact.sa_handler;
    }

    return SIG_ERR;
}

