#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        printf("Child is exiting to become a zombie temporarily...\n");
        exit(0);
    } else {
        printf("Parent Process: PID = %d. Sleeping for 3 seconds while child exits.\n", getpid());
        sleep(3);
        printf("Parent awake. Now exiting.\n");
    }

    return 0;
}
