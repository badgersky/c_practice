#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* th_sum(void* arg) {
    int* p = (int*)arg;
    int* res = malloc(sizeof(int));
    *res = p[0] + p[1];

    return (void*) res;
}

void* th_dif(void* arg) {
    int* p = (int*)arg;
    int* res = malloc(sizeof(int));
    *res = p[0] - p[1];

    return (void*) res;
}

int main() {
    int* nums = malloc(sizeof(int));
    int x, y;
    int* res_dif;
    int* res_sum;

    printf("wpisz dwie liczby\n");
    scanf("%d %d", &x, &y);
    nums[0] = x;
    nums[1] = y;

    pthread_t th_id1, th_id2;

    pthread_create(&th_id1, NULL, &th_sum, nums);
    pthread_create(&th_id2, NULL, &th_dif, nums);

    pthread_join(th_id1, (void**) &res_sum);
    pthread_join(th_id2, (void**) &res_dif);

    printf("%d + %d = %d\n", x, y, *res_sum);
    printf("%d - %d = %d\n", x, y, *res_dif);

    free(nums);
    free(res_sum);
    free(res_dif);
}