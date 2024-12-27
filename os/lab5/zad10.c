#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void* thread(void* arg) {
    int private_num = pthread_self() % 1000;
    pthread_setspecific(*(pthread_key_t*)arg, &private_num);

    printf(
        "wątek %ld, wartość zmiennej prywatnej: %d\n\n", 
        pthread_self(), 
        *(int*)pthread_getspecific(*(pthread_key_t*)arg)
        );
}

int main() {
    pthread_key_t key;
    pthread_t th_id1, th_id2;

    pthread_key_create(&key, NULL);
    pthread_create(&th_id1, NULL, &thread, &key);
    pthread_create(&th_id2, NULL, &thread, &key);

    sleep(2);
    pthread_join(th_id1, NULL);
    pthread_join(th_id2, NULL);
    pthread_key_delete(key);
}