#ifndef _COMPAT_SEMAPHORE_H_
#define _COMPAT_SEMAPHORE_H_

#ifdef _WIN32
#include <windows.h>

typedef HANDLE sem_t;

static inline int sem_init(sem_t *sem, int pshared, unsigned int value) {
    (void)pshared;
    *sem = CreateSemaphore(NULL, (LONG)value, 0x7FFFFFFF, NULL);
    return (*sem != NULL) ? 0 : -1;
}

static inline int sem_wait(sem_t *sem) {
    return (WaitForSingleObject(*sem, INFINITE) == WAIT_OBJECT_0) ? 0 : -1;
}

static inline int sem_post(sem_t *sem) {
    return ReleaseSemaphore(*sem, 1, NULL) ? 0 : -1;
}

static inline int sem_destroy(sem_t *sem) {
    return CloseHandle(*sem) ? 0 : -1;
}

#else
#include_next <semaphore.h>
#endif

#endif
