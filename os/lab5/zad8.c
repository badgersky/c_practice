#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TH_NUM 20

void cleanup_routine(void* arg) {
    printf("wątek nr %d został anulowany\n", *(int*)arg);
    free(arg);
}

void* thread(void* arg) {
    pthread_cleanup_push(&cleanup_routine, arg);
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
    int i = *(int*)arg;

    while (1) {
        sleep(i + 1);
        printf("wątek nr %d %ld\n", i, pthread_self());
    }    

    free(arg);
    pthread_cleanup_pop(0);
}

int main() {
    pthread_t th_id[TH_NUM];

    for (int i = 0; i < TH_NUM; i++) {
        int* a = malloc(sizeof(int));
        *a = i;

        pthread_create(&th_id[i], NULL, &thread, a);
    }

    sleep(5);

    for (int i = 0; i < TH_NUM; i++) {
        sleep(1);
        pthread_cancel(th_id[i]);
    }

    for (int i = 0; i < TH_NUM; i++) {
        pthread_join(th_id[i], NULL);
    }
}