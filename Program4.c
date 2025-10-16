#include <stdio.h>
#include <unistd.h>
int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Hello from child! PID = %d\n", getpid());
    } else if (pid > 0) {
        // Parent process
        printf("Hello from parent! PID = %d\n", getpid());
    } else {
        printf("Fork failed!\n");
    }

    return 0;
}

