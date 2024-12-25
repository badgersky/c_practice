#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* th_sum(void* arg) {
    int* p = (int*)arg;
    int x = p[0];
    int y = p[1];

    printf("%d + %d = %d\n", x, y, x + y);
}

void* th_dif(void* arg) {
    int* p = (int*)arg;
    int x = p[0];
    int y = p[1];

    printf("%d - %d = %d\n", x, y, x - y);
}

int main() {
    int* nums = malloc(sizeof(int));
    int x, y;

    printf("wpisz dwie liczby\n");
    scanf("%d %d", &x, &y);
    nums[0] = x;
    nums[1] = y;

    pthread_t th_id1, th_id2;

    pthread_create(&th_id1, NULL, &th_sum, nums);
    pthread_create(&th_id2, NULL, &th_dif, nums);

    pthread_join(th_id1, NULL);
    pthread_join(th_id2, NULL);

    free(nums);
}