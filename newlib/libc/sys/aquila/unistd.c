#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

#include "syscalls.h"

int unlink(const char *path)
{
    int ret;
    SYSCALL1(ret, SYS_UNLINK, path);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

pid_t setsid()
{
    /* TODO */
    return 1;
}

int getpagesize(void)
{
    /* FIXME */
    return 4096;
}

gid_t getegid(void)
{
    errno = -ENOSYS;
    return -1;
}

int fchown(int fd, uid_t owner, gid_t group)
{
    errno = -ENOSYS;
    return -1;
}

pid_t tcgetpgrp(int fd)
{
    errno = -ENOSYS;
    return -1;
}

int tcsetpgrp(int fd, pid_t pid)
{
    errno = -ENOSYS;
    return -1;
}

pid_t getpgrp(void)
{
    int ret;
    SYSCALL0(ret, SYS_GETPGRP);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

int nice(int inc)
{
    errno = -ENOSYS;
    return -1;
}

pid_t getppid(void)
{
    errno = -ENOSYS;
    return -1;
}

int setuid(uid_t uid)
{
    errno = -ENOSYS;
    return -1;
}

ssize_t readlink(const char *pathname, char *buf, size_t bufsiz)
{
    errno = -ENOSYS;
    return -1;
}

uid_t geteuid(void)
{
    errno = -ENOSYS;
    return -1;
}

int setgid(gid_t gid)
{
    errno = -ENOSYS;
    return -1;
}

int seteuid(uid_t euid)
{
    errno = -ENOSYS;
    return -1;
}

int setegid(gid_t egid)
{
    errno = -ENOSYS;
    return -1;
}

int truncate(const char *path, off_t len)
{
    errno = ENOSYS;
    return -1;
}

int ftruncate(int fd, off_t len)
{
    errno = ENOSYS;
    return -1;
}

long pathconf(const char *path, int name)
{
    errno = ENOSYS;
    return -1;
}

long fpathconf(int fd, int name)
{
    errno = ENOSYS;
    return -1;
}

void sync(void)
{
    return;
}

unsigned int sleep(unsigned int seconds)
{
    errno = ENOSYS;
    return -1;
}

unsigned int alarm(unsigned int seconds)
{
    errno = ENOSYS;
    return -1;
}

int dup(int oldfd)
{
    return fcntl(oldfd, F_DUPFD, 0);
}

int dup2(int oldfd, int newfd)
{
    return fcntl(oldfd, F_DUPFD, newfd);
}

pid_t vfork(void)
{
    return fork();
}

int rmdir(const char *path)
{
    /*
    int ret;
    SYSCALL1(ret, SYS_RMDIR, path);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }
    */

    errno = ENOSYS;
    return -1;

    return 0;
}

int close(int fildes)
{
    int ret;
    SYSCALL1(ret, SYS_CLOSE, fildes);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

int _execve(const char *path, char *const argv[], char *const envp[])
{
    int ret;
    SYSCALL3(ret, SYS_EXECVE, path, argv, envp);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

__attribute__((noreturn)) void _exit(int status)
{
    /* Does not return */
    SYSCALL1((int){0}, SYS_EXIT, status);
}

pid_t fork(void)
{
    pid_t ret;
    SYSCALL0(ret, SYS_FORK);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

int fstat(int fildes, struct stat *buf)
{
    int ret;
    SYSCALL2(ret, SYS_FSTAT, fildes, buf);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

pid_t getpid(void)
{
    pid_t ret;
    SYSCALL0(ret, SYS_GETPID);
    return ret;
}

int chown(const char *path, uid_t owner, gid_t group)
{
    /*
    int ret;
    SYSCALL3(ret, SYS_CHOWN, path, owner, group);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }
    */

    errno = ENOSYS;
    return -1;

    return 0;
}

int utime(const char *path, const struct utimebuf *times)
{
    /*
    int ret;
    SYSCALL2(ret, SYS_UTIME, path, times);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }
    */

    errno = ENOSYS;
    return -1;

    return 0;
}

int access(const char *path, int mode)
{
    int ret;
    SYSCALL2(ret, SYS_ACCESS, path, mode);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int link(const char *old, const char *new)
{
    errno = ENOSYS;
    return -1;
}

off_t lseek(int fildes, off_t offset, int whence)
{
    off_t ret;
    SYSCALL3(ret, SYS_LSEEK, fildes, offset, whence);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

ssize_t read(int fildes, void *buf, size_t nbytes)
{
    int ret;
    SYSCALL3(ret, SYS_READ, fildes, buf, nbytes);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

void *sbrk(ptrdiff_t incr)
{
    void *ret;
    SYSCALL1(ret, SYS_SBRK, incr);

    /* TODO */
    return ret;
}

int stat(const char *file, struct stat *st)
{
    return 0;
}

ssize_t write(int fildes, const void *buf, size_t nbytes)
{
    ssize_t ret;
    SYSCALL3(ret, SYS_WRITE, fildes, buf, nbytes);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

int pipe(int fd[2])
{
    int ret;
    SYSCALL1(ret, SYS_PIPE, fd);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int chdir(const char *path)
{
    int ret;
    SYSCALL1(ret, SYS_CHDIR, path);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

char *getcwd(char *buf, size_t size)
{
    int ret;
    SYSCALL2(ret, SYS_GETCWD, buf, size);

    if (ret < 0) {
        errno = -ret;
        return NULL;
    }

    return buf;
}

int setpgid(pid_t pid, pid_t pgid)
{
    int ret;
    SYSCALL2(ret, SYS_SETPGID, pid, pgid);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int lstat(const char *path, struct stat *buf)
{
    int ret;
    SYSCALL2(ret, SYS_LSTAT, path, buf);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

uid_t getuid(void)
{
    uid_t uid;
    SYSCALL0(uid, SYS_GETUID);
    return uid;
}

gid_t getgid(void)
{
    gid_t gid;
    SYSCALL0(gid, SYS_GETGID);
    return gid;
}

long sysconf(int name)
{
    long ret;
    SYSCALL1(ret, SYS_SYSCONF, name);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}
