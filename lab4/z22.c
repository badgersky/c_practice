#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sum_diagonals(FILE *fd, int n);

int main() {
    int n;
    FILE *fd;
    fd = fopen("dane22", "r");
    if (!fd) {
        printf("file error");
        exit(1);
    }

    fscanf(fd, "%d", &n);
    printf("Sum of numbers on both diagonals is %lf", sum_diagonals(fd, n));
}

double sum_diagonals(FILE *fd, int n) {
    double num, sum = 0, zero = 0.;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(fd, "%lf", &num);
            if ((i == j) && (num >= zero)) {
                sum += num;
            }
            if ((j == (n - i - 1)) && (num - 0.5 >= zero)) {
                sum += num;
            }
        }
    }
    return sum;
}
