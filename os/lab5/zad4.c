#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* detached_th(void* args) {
    printf("wątek rozdzielny: %ld\n", pthread_self());
    for (int i = 0; i < 5; i++) {
        sleep(1);
        printf("%ld iteracja %d\n", pthread_self(), i);
    }
}

void* joinable_th(void* args) {
    printf("wątek łączny: %ld\n", pthread_self());
}

int main() {
    pthread_t th_id1, th_id2;

    pthread_create(&th_id1, NULL, &detached_th, NULL);
    pthread_detach(th_id1);

    pthread_create(&th_id2, NULL, &joinable_th, NULL);

    printf("oczekiwanie na wątek: %ld\n", th_id2);
    pthread_join(th_id2, NULL);
    printf("wątek %ld połączony\n", th_id2);

    printf("oczekiwanie na zakończenie wątku %ld\n", th_id1);
    pthread_exit(0);
}