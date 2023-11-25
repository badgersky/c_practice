#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

void write_to_array(int *arr, int n);
int min(const int *arr, int n, int *m);
int max(const int *arr, int n, int *m);
void print_array(int *arr, int n);

int main() {
    int *t1, *t2, n, mx, mn, k, l;
    t1 = NULL, t2 = NULL;
    printf("Enter length of arrays:\n");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid input");
        exit(1);
    }

    t1 = (int *) malloc((unsigned) n * sizeof(int));
    t2 = (int *) malloc((unsigned) n * sizeof(int));

    if (!(t1 || t2)) {
        printf("Allocation error");
        exit(1);
    }

    write_to_array(t1, n);
    print_array(t1, n);
    k = max(t1, n, &mx);
    printf("Maximum value: %d, Index: %d\n", mx, k);
    l = min(t1, n, &mn);
    printf("Minimal value: %d, Index: %d\n", mn, l);

    memcpy(t2, t1, n * sizeof(int));

    if (t1) {
        free(t1);
        t1 = NULL;
    }
    if (t2) {
        free(t1);
        t2 = NULL;
    }
}

void write_to_array(int *arr, int n) {
    srand(time(0));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}


void print_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int max(const int *arr, int n, int *m) {
    *m = arr[0];
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > *m) {
            *m = arr[i];
            k = i;
        }
    }
    return k;
}

int min(const int *arr, int n, int *m) {
    *m = arr[0];
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < *m) {
            *m = arr[i];
            k = i;
        }
    }
    return k;
}