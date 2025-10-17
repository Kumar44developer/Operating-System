#include <stdio.h>
#include <unistd.h>

int main() {
    printf("My PID is %d\n", getpid());
    printf("My Parent's PID is %d\n", getppid());
    return 0;
}

