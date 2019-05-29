#ifndef _AQUILA_SYSCALLS_H
#define _AQUILA_SYSCALLS_H

#define SYS_EXIT    1
#define SYS_CLOSE   2
#define SYS_EXECVE  3
#define SYS_FORK    4   
#define SYS_FSTAT   5
#define SYS_GETPID  6
#define SYS_ISATTY  7
#define SYS_KILL    8 
#define SYS_LSEEK   10
#define SYS_OPEN    11
#define SYS_READ    12
#define SYS_SBRK    13
#define SYS_UNLINK  16
#define SYS_WAITPID 17
#define SYS_WRITE   18
#define SYS_IOCTL   19
#define SYS_SIGACT  20 
#define SYS_READDIR 21 
#define SYS_MOUNT   22 
#define SYS_MKDIR   23
#define SYS_UNAME   24
#define SYS_PIPE    25
#define SYS_FCNTL   26
#define SYS_CHDIR   27
#define SYS_GETCWD  28
#define SYS_SETPGID 32
#define SYS_MKNOD   33
#define SYS_LSTAT   34
#define SYS_AUTH    35
#define SYS_GETUID  36
#define SYS_GETGID  37
#define SYS_MMAP    38
#define SYS_MUNMAP  39

#define SYS_SOCKET  40
#define SYS_ACCEPT  41
#define SYS_BIND    42
#define SYS_CONNECT 43
#define SYS_LISTEN  44
#define SYS_SEND    45
#define SYS_RECV    46

#define SYS_UMASK   47
#define SYS_CHMOD   48
#define SYS_SYSCONF 49
#define SYS_GETTIMEOFDAY 50
#define SYS_ACCESS  51
#define SYS_SIGMASK 52
#define SYS_SELECT  53
#define SYS_GETPGRP 54

#define SYSCALL3(ret, v, arg1, arg2, arg3) \
    asm volatile("int $0x80;":"=a"(ret):"a"(v), "b"(arg1), "c"(arg2), "d"(arg3));
#define SYSCALL2(ret, v, arg1, arg2) \
    asm volatile("int $0x80;":"=a"(ret):"a"(v), "b"(arg1), "c"(arg2));
#define SYSCALL1(ret, v, arg1) \
    asm volatile("int $0x80;":"=a"(ret):"a"(v), "b"(arg1));
#define SYSCALL0(ret, v) \
    asm volatile("int $0x80;":"=a"(ret):"a"(v));

#endif /* ! _AQUILA_SYSCALLS_H */
