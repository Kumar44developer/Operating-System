#include <stdio.h>
#include <pthread.h>
int sum = 0;
pthread_mutex_t lock;

void* addNumbers(void* arg) {
    int n = *(int*)arg;
    pthread_mutex_lock(&lock);
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int n1 = 5, n2 = 10;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, addNumbers, &n1);
    pthread_create(&t2, NULL, addNumbers, &n2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final sum = %d\n", sum);

    pthread_mutex_destroy(&lock);
    return 0;
}

