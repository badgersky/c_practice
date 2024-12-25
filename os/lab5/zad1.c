#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* print_ids(void* args) {
    printf("id wątku: %ld\n", pthread_self());
    printf("id procesu: %d\n", getpid());
}

int main() {
    pthread_t th_id1, th_id2;

    pthread_create(&th_id1, NULL, &print_ids, NULL);
    pthread_create(&th_id2, NULL, &print_ids, NULL);

    pthread_join(th_id1, NULL);
    pthread_join(th_id2, NULL);

    return 0;
}