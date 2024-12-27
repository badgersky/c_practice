#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

sem_t s;

void cleanup_routine(void* arg) {
    int i = *(int*)arg;
    printf("wątek nr %d został anulowany\n", i);

    sem_post(&s);
}

void* thread(void* arg) {
    int i = *(int*)arg;

    pthread_cleanup_push(&cleanup_routine, arg);
    sem_wait(&s);
    while (1) {
        sleep(1);
        printf("wątek nr %d %ld\n", i, pthread_self());
    }
    pthread_cleanup_pop(0);
}

int main() {
    pthread_t th_id1, th_id2;
    int x = 1;
    int y = 2;

    sem_init(&s, 0, 1);
    
    pthread_create(&th_id1, NULL, &thread, &x);
    sleep(1);
    pthread_create(&th_id2, NULL, &thread, &y);
    
    sleep(5);
    pthread_cancel(th_id1);

    pthread_join(th_id1, NULL);
    pthread_join(th_id2, NULL);

    sem_destroy(&s);
}