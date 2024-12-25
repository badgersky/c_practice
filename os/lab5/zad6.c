#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <signal.h>

#define SEM_V 6
sem_t s;

void* thread(void* arg) {
    int num = *(int*)arg;

    sem_wait(&s);
    while (1) {
        sleep(1);
        printf("wątek numer: %d\n", num);
    }

    free(arg);
}

int main() {
    pthread_t th_id;
    sem_init(&s, 0, SEM_V   );
    for (int i = 1; i < 100; i++) { 
        int* x = malloc(sizeof(int));
        *x = i;
        pthread_create(&th_id, NULL, &thread, x);
    }
    
    for (int i = 0; i < 100; i++)
        pthread_join(th_id, NULL);
    sem_destroy(&s);
}
