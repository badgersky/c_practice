#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void cleanup_routine(void* arg) {
    printf("wątek %ld został anulowany\n", *(long*)arg);
}

void* thread(void* arg) {
    pthread_cleanup_push(&cleanup_routine, (void*)pthread_self());
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
    printf("anulowanie wyłączone\n\n");
    sleep(2);

    for (int x = 0; x < 8; x++) {
        sleep(1);
        printf("wątek %ld\n", pthread_self());
    }

    printf("\nanulowanie włączone\n\n");
    sleep(2);
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_testcancel();

    pthread_cleanup_pop(0);
}

int main() {
    pthread_t th_id;    

    pthread_create(&th_id, NULL, &thread, NULL);

    sleep(1);
    pthread_cancel(th_id);

    pthread_join(th_id, NULL);
}