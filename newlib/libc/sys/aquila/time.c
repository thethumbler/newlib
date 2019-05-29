#include <time.h>
#include <sys/resource.h>
#include <errno.h>

#include "syscalls.h"

int nanosleep(const struct timespec  *rqtp, struct timespec *rmtp)
{
    return 0;
}

int getrusage(int who, struct rusage *usage)
{
    errno = -ENOSYS;
    return -1;
}

//int gettimeofday(struct timeval *__restrict tv, void *__restrict tz)
int gettimeofday(struct timeval *tv, void *tz)
{
    int ret;
    SYSCALL2(ret, SYS_GETTIMEOFDAY, tv, tz);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int clock_getres(clockid_t clk_id, struct timespec *res)
{
    errno = -ENOSYS;
    return -1;
}

int clock_gettime(clockid_t clk_id, struct timespec *tp)
{
    errno = -ENOSYS;
    return -1;
}

int clock_settime(clockid_t clk_id, const struct timespec *tp)
{
    errno = -ENOSYS;
    return -1;
}
