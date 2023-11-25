#include <stdio.h>
#include <math.h>

typedef struct CO {
    double re;
    double im;
} COMPLEX;

void rkw(double a, double b, double c, COMPLEX *n1, COMPLEX *n2);
COMPLEX add1(COMPLEX *x1, COMPLEX *x2);
void add2(COMPLEX *x1, COMPLEX *x2, COMPLEX *res);

int main()
{
    COMPLEX co_num1, co_num2, sum;
    double a, b, c;
    printf("Enter a, b, c:\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    rkw(a, b, c, &co_num1, &co_num2);
    printf("x1 = %lf %lf\n", co_num1.re, co_num1.im);
    printf("x2 = %lf %lf\n", co_num2.re, co_num2.im);

    sum = add1(&co_num1, &co_num2);
    printf("result1 = %lf %lf\n", sum.re, sum.im);
    add2(&co_num1, &co_num2, &sum);
    printf("result1 = %lf %lf\n", sum.re, sum.im);
}

void rkw(double a, double b, double c, COMPLEX *n1, COMPLEX *n2) {
    double delta = b * b - 4 * a * c;
    double re, im;
    if (delta >= 0) {
        // real numbers solution
        n1->re = (-b + sqrt(delta)) / (2 * a);
        n1->im = 0;
        n2->re = (-b - sqrt(delta)) / (2 * a);
        n2->im = 0;

    } else {
        // complex numbers
        re = -b / (2 * a);
        im = sqrt(fabs(pow(b / (2 * a), 2) - c / a));
        n1->re = re;
        n2->re = re;
        n1->im = im;
        n2->im = -im;
    }
}

COMPLEX add1(COMPLEX *x1, COMPLEX *x2) {
    COMPLEX res;
    res.re = x1->re + x2->re;
    res.im = x1->im + x2->im;
    return res;
}


void add2(COMPLEX *x1, COMPLEX *x2, COMPLEX *res) {
    res->re = x1->re + x2->re;
    res->im = x1->im + x2->im;
}