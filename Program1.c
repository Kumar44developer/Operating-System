#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#ifdef _WIN32
#include <process.h>
#ifndef WIFEXITED
#define WIFEXITED(status) (1)
#define WEXITSTATUS(status) (status)
#endif
#else
#include <sys/wait.h>
#endif

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child process running\n");
        exit(5);  // Child exits with status 5
    } else {
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Child exited with status: %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}
