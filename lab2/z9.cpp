#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define pi 3.1415

#pragma warning (disable: 4996)

void circle(double r, double* w1, double* w2);

int main()
{
    double r, area, circuit;
    int ret;
    printf("Enter radius:\n");
    ret = scanf("%lf", &r);

    if (ret != 1) {
        printf("Invalid input");
        exit(1);
    }

    circle(r, &area, &circuit);
    printf("Results for r = %lf\n", r);
    printf("Area = %lf\n", area);
    printf("Circuit = %lf\n", circuit);
}

void circle(double r, double* w1, double* w2) {
    *w1 = pi * pow(r, 2);
    *w2 = 2 * pi * r;
}