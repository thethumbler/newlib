#include <stdlib.h>
#include <errno.h>
#include <sys/ioctl.h>

#include "syscalls.h"

int unlockpt(int fd)
{
    return 0;
}

int grantpt(int fd)
{
    return 0;
}

const char *ptsname(int fd)
{
    static char pts_fn[128];

    int pts_id = 0;
    ioctl(fd, TIOCGPTN, &pts_id);

    snprintf(pts_fn, 128, "/dev/pts/%d", pts_id);

    return pts_fn;
}

