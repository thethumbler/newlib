#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>

#include "syscalls.h"

int socket(int domain, int type, int protocol)
{
    int err;
    SYSCALL3(err, SYS_SOCKET, domain, type, protocol);

    if (err < 0) {
        errno = -err;
        return -1;
    }

    return err;
}

int accept(int fd, const struct sockaddr *addr, socklen_t *addrlen)
{
    int err;
    SYSCALL3(err, SYS_ACCEPT, fd, addr, addrlen);

    if (err < 0) {
        errno = -err;
        return -1;
    }

    return err;
}

int bind(int fd, const struct sockaddr *addr, socklen_t addrlen)
{
    int err;
    SYSCALL3(err, SYS_BIND, fd, addr, addrlen);

    if (err < 0) {
        errno = -err;
        return -1;
    }

    return 0;
}

int connect(int fd, const struct sockaddr *addr, socklen_t addrlen)
{
    int err;
    SYSCALL3(err, SYS_CONNECT, fd, addr, addrlen);

    if (err < 0) {
        errno = -err;
        return -1;
    }

    return err;
}

int listen(int fd, int backlog)
{
    int err;
    SYSCALL2(err, SYS_LISTEN, fd, backlog);

    if (err < 0) {
        errno = -err;
        return -1;
    }

    return 0;
}

struct socket_io_syscall {
    int fd;
    void *buf;
    size_t len;
    int flags;
} __attribute__((packed));

ssize_t send(int fd, void *buf, size_t len, int flags)
{
    struct socket_io_syscall s = {fd, buf, len, flags};

    ssize_t err;
    SYSCALL1(err, SYS_SEND, &s);

    if (err < 0) {
        errno = -err;
        return -1;
    }

    return err;
}

ssize_t recv(int fd, void *buf, size_t len, int flags)
{
    struct socket_io_syscall s = {fd, buf, len, flags};

    ssize_t err;
    SYSCALL1(err, SYS_RECV, &s);

    if (err < 0) {
        errno = -err;
        return -1;
    }

    return err;
}

