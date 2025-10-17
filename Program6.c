#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Sleeping for 3 seconds...\n");
    sleep(3);
    printf("Awake now!\n");
    return 0;
}
