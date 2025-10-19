#include <stdio.h>
#include <pthread.h>

void* printNumber(void* arg) {
    int num = *(int*)arg;
    printf("Number from thread: %d\n", num);
    return NULL;
}

int main() {
    pthread_t thread;
    int value = 42;

    pthread_create(&thread, NULL, printNumber, &value);
    pthread_join(thread, NULL);

    printf("Main thread completed.\n");
    return 0;
}

