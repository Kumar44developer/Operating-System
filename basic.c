//writing the code for the operating system here
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    printf("\nCaught signal %d (Ctrl+C pressed). Exiting gracefully.\n", sig);
    _exit(0);
}

int main() {
    signal(SIGINT, handle_sigint);
    printf("Running... Press Ctrl+C to stop.\n");

    while(1) {
        sleep(1);
    }

    return 0;
}













