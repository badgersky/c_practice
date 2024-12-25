#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <signal.h>

sem_t semaphore;

void sig_handler(int sig) {
    sem_post(&semaphore);
}

void* thread(void* arg) {
    printf("wątek %ld czeka na sygnał\n", pthread_self());
    sem_wait(&semaphore);
    printf("przechwycono sygnał\n");
}

int main() {
    signal(10, sig_handler);

    sem_init(&semaphore, 0, 0);
    pthread_t th_id;
    pthread_create(&th_id, NULL, &thread, NULL);
    pthread_detach(th_id);

    sleep(6);
    pthread_kill(th_id, 10);
    sem_destroy(&semaphore);
    pthread_exit(0);
}