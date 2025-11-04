#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main() {
    int pipefd[2];
    pipe(pipefd);

    pid_t pid = fork();
