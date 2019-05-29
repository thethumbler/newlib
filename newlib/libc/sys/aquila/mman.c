#include <sys/mman.h>
#include <sys/errno.h>

#include "syscalls.h"

void *mmap(void *addr, size_t len, int prot, int flags, int fd, off_t off)
{
    struct {
        void    *addr;
        size_t  len;
        int     prot;
        int     flags;
        int     fd;
        off_t   off;
    } __attribute__((packed)) args = {
        addr, len, prot, flags, fd, off
    };

    void *ret;
    int err;

    SYSCALL2(err, SYS_MMAP, &args, &ret);

    if (err < 0) {
        errno = -err;
        return MAP_FAILED;
    }

    return ret;
}

int munmap(void *addr, size_t len)
{
    int err;
    SYSCALL2(err, SYS_MUNMAP, addr, len);

    if (err < 0) {
        errno = -err;
        return -1;
    }

    return 0;
}

