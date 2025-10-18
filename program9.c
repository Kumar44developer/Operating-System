#include <stdio.h>
#include <stdlib.h>      
#include <unistd.h>      
#include <sys/types.h>
#include <sys/wait.h>    
int main() {
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        printf("Error in creating a child process\n");
        exit(1);
    }
    else if (pid > 0) {
        printf("Parent Process\nParent PID = %d\nChild PID = %d\n", getpid(), pid);
        wait(NULL);  
        printf("Parent resumes\n");
    }
    else {
        printf("Child Process\n");
        printf("Parent PID = %d, Child PID = %d\n", getppid(), getpid());
       execlp("/bin/ls", ls, NULL);
      }
    return 0;
}















