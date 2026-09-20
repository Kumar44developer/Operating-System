#ifndef _COMPAT_SYS_WAIT_H_
#define _COMPAT_SYS_WAIT_H_

#ifdef _WIN32
#include <process.h>
#define WIFEXITED(status)   (((status) & 0x7f) == 0)
#define WEXITSTATUS(status) (((status) & 0xff00) >> 8)
#define WIFSIGNALED(status) (((signed char) (((status) & 0x7f) + 1) >> 1) > 0)
#define WTERMSIG(status)    ((status) & 0x7f)
#define WIFSTOPPED(status)  (((status) & 0xff) == 0x7f)
#define WSTOPSIG(status)    (WEXITSTATUS(status))

#ifndef wait
int wait(int *status);
#endif

#else
#include_next <sys/wait.h>
#endif

#endif
