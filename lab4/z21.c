#include <stdlib.h>
#include <stdio.h>

void read_interval(int *a, int*b);
int sum_below_diag(FILE *f, int n, int m, int a, int b);

int main() {
    FILE *fd;
    fd = fopen("dane2122", "r");
    if (!fd) {
        printf("file error");
        exit(1);
    }

    int sum, n, m, a, b;
    read_interval(&a, &b);
    printf("%d %d\n", a, b);
    fscanf(fd, "%d %d", &n, &m);
    sum = sum_below_diag(fd, n, m, a, b);
    printf("Sum of elements below matrix diagonal is %d", sum);
}

void read_interval(int *a, int*b) {
    printf("input a, b, both ends of interval:\n");
    int ret = scanf("%d %d", a, b);
    if (ret != 2) {
        printf("wrong input");
        exit(1);
    }
}

int sum_below_diag(FILE *f, int n, int m, int a, int b) {
    int sum = 0, num;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(f, "%d", &num);
            if (j < i) {
                if (a <= num && num <= b) {
                    sum += num;
                }
            }
        }
    }
    return sum;
}
