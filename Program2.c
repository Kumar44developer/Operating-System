#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main() {
    int pipefd[2];
    pipe(pipefd);

    pid_t pid = fork();

    if (pid == 0) {
        // Child reads from pipe
        close(pipefd[1]); // Close write end
        char buffer[100];
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(pipefd[0]);
    } else {
        // Parent writes to pipe
        close(pipefd[0]); // Close read end
        char msg[] = "Hello from parent";
        write(pipefd[1], msg, strlen(msg) + 1);
        close(pipefd[1]);
    }

    return 0;
}
