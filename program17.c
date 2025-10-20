#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void cleanup(void *arg) {
    printf("Cleaning up resources: %s\n", (char *)arg);
}

void *thread_func(void *arg) {
    pthread_cleanup_push(cleanup, "Thread resources");
    
    for (int i = 0; i < 10; i++) {
        printf("Thread running %d\n", i);
        sleep(1);  
    }
    
    pthread_cleanup_pop(1);  
    return NULL;
}
int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, thread_func, NULL);

    sleep(3);
    pthread_cancel(tid);  

    pthread_join(tid, NULL);
    printf("Thread has been canceled\n");
    return 0;
}


