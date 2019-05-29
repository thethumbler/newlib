#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

#include "syscalls.h"

int scandir(const char *dirp, struct dirent ***namelist,
              int (*filter)(const struct dirent *),
              int (*compar)(const struct dirent **, const struct dirent **))
{
    errno = -ENOSYS;
    return -1;
}

int alphasort(const struct dirent **a, const struct dirent **b)
{
    errno = -ENOSYS;
    return -1;
}

int versionsort(const struct dirent **a, const struct dirent **b)
{
    errno = -ENOSYS;
    return -1;
}

DIR *opendir(const char *dirname)
{
    int fd = open(dirname, O_SEARCH);

    if (fd == -1)
        return NULL;

    DIR *dir = malloc(sizeof(DIR));
    dir->dd_fd = fd;

    return dir;
}

struct dirent *readdir(DIR *dir)
{
    static struct dirent dirent;
    int ret;
    SYSCALL2(ret, SYS_READDIR, dir->dd_fd, &dirent);

    if (ret <= 0) {
        errno = -ret;
        memset(&dirent, 0, sizeof(dirent));
        return NULL;
    }

    return &dirent;
}

int closedir(DIR *dir)
{
    close(dir->dd_fd);
    free(dir);
}

