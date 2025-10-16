#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main() {
    pid_t pid, mypid, myppid;

    mypid = getpid();
    printf("Before fork: PID = %d\n", mypid);

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        mypid = getpid();
        myppid = getppid();
        printf("This is the child process.\n");
        printf("Child PID = %d, Parent PID = %d\n", mypid, myppid);
    } else {
        // Parent process
        mypid = getpid();
        myppid = getppid();
        printf("This is the parent process.\n");
        printf("Parent PID = %d, Parent's Parent PID = %d\n", mypid, myppid);
    }

    return 0;
}
