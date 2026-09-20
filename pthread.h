#ifndef _COMPAT_PTHREAD_H_
#define _COMPAT_PTHREAD_H_

#ifdef _WIN32
#include <windows.h>
#include <process.h>

typedef HANDLE pthread_t;
typedef CRITICAL_SECTION pthread_mutex_t;
typedef void pthread_attr_t;
typedef void pthread_mutexattr_t;

static inline int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg) {
    (void)attr;
    *thread = (HANDLE)_beginthreadex(NULL, 0, (unsigned int (__stdcall *)(void *))start_routine, arg, 0, NULL);
    return (*thread != NULL) ? 0 : -1;
}

static inline int pthread_join(pthread_t thread, void **retval) {
    (void)retval;
    WaitForSingleObject(thread, INFINITE);
    CloseHandle(thread);
    return 0;
}

static inline int pthread_cancel(pthread_t thread) {
    return TerminateThread(thread, 0) ? 0 : -1;
}

static inline int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr) {
    (void)attr;
    InitializeCriticalSection(mutex);
    return 0;
}

static inline int pthread_mutex_lock(pthread_mutex_t *mutex) {
    EnterCriticalSection(mutex);
    return 0;
}

static inline int pthread_mutex_unlock(pthread_mutex_t *mutex) {
    LeaveCriticalSection(mutex);
    return 0;
}

static inline int pthread_mutex_destroy(pthread_mutex_t *mutex) {
    DeleteCriticalSection(mutex);
    return 0;
}

typedef struct {
    void (*routine)(void *);
    void *arg;
} _pthread_cleanup_entry;

#define pthread_cleanup_push(routine, arg) \
    do { \
        void (*__cleanup_routine)(void *) = (routine); \
        void *__cleanup_arg = (arg);

#define pthread_cleanup_pop(execute) \
        if (execute) { \
            __cleanup_routine(__cleanup_arg); \
        } \
    } while (0)

#else
#include_next <pthread.h>
#endif

#endif
