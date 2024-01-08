#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc_x(double (*func)(), const double *x, double *res);

int main() {
    double x, res1, res2;
    int ret;
    printf("Enter number:\n");
    ret = scanf("%lf", &x);
    if (ret != 1) {
        printf("invalid input");
        exit(1);
    }

    calc_x(cos, &x, &res1);
    calc_x(sin, &x, &res2);

    printf("result 1 = %lf\n", res1);
    printf("result 2 = %lf\n", res2);
}

void calc_x(double (*func)(double), const double *x, double *res) {
    *res = pow(*x, 2) + func(*x);
}
