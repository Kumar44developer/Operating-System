#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 3;  
int x = 0;    

int wait(int s) {
    return (--s);
}


int signal(int s) {
    return (++s);
}
void producer() {
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
   x++;
    printf("\nProducer produces item %d", x);

    mutex = signal(mutex);
}

void consumer() {
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    
    printf("\nConsumer consumes item %d", x);
    x--;

    mutex = signal(mutex);
}

int main() {
    int choice;

    printf("\n--- Producer Consumer Simulation (Semaphore) ---");
while (1) {
        printf("\n\n1. Produce\n2. Consume\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (mutex == 1 && empty != 0)
                    producer();
                else
                    printf("\nBuffer is FULL! Producer cannot produce.");
                break;
            case 2:
                if (mutex == 1 && full != 0)
                    consumer();
                else
                    printf("\nBuffer is EMPTY! Consumer cannot consume.");
                break;












