#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    int pid = fork();

    if (pid == 0) {
        printf("Child process running...\n");
        sleep(2);
        printf("Child process finished.\n");
    } else {
        wait(NULL); // parent waits for child to complete
        printf("Parent process resumes after child completes.\n");
    }

    return 0;
}

