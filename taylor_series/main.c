#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma warning (disable: 4996)

void validate_n_m(int const *np, int const *mp, int ret);
int validate_a_b_epx(double *a, double *b, double const *eps, int ret);
void series(double x, int m, double eps, int *condition);

int main() {
    int n, m, ret, ab_check, condition;
    double a, b, eps, dx, i;

    printf("Enter n, m:\n");  //m n input and validation
    ret = scanf("%d %d", &n, &m);
    validate_n_m(&n, &m, ret);

    printf("Enter a, b - endpoints of interval, and eps - accuracy:\n");  //a b eps input and validation
    ret = scanf("%lf %lf %lf", &a, &b, &eps);
    ab_check = validate_a_b_epx(&a, &b, &eps, ret);
    if (ab_check == 0) {
        printf("Invalid input");
        exit(2);
    }

    dx = (b - a) / n;
    i = a;
    while (i <= b) {
        series(i, m, eps, &condition);
        i += dx;
    }
}

void validate_n_m(int const *np, int const *mp, int ret) {
    if (*np * (*mp) <= 0 || ret != 2) {
            printf("Invalid input");
            exit(2);
    }
}

int validate_a_b_epx(double *a, double *b, double const *eps, int ret) {
    double err = 1e-10;
    if (ret != 3) {
        return 0;
    }
    if (*a > *b) {
        double z = *b;
        *b = *a;
        *a = z;
    }
    if (fabs(*a + 1.) < err || fabs(*b - 1.) < err) {
        return 0;
    }
    if (fabs(*a - *b) < err) {
        return 0;
    }
    if (*eps <= err) {
        return 0;
    }
    return 1;
}

void series(double x, int m, double eps, int *condition) {
    double strict_v = pow((1 - x), -3./2.);
    int i = 1;
    double prev = 1., res = 1., next;

    while (1) {
        if (i >= m) {
            *condition = 1;
            break;
        }
        if (fabs(strict_v - res) < eps) {
            *condition = 2;
            break;
        }

        next = prev * ((2. * i + 1.) / (2. * i));
        prev = next;
        res += next * pow(x, i);
        i++;
    }
    printf("%lf\t%lf\t%lf\t%d\t%d\n", x, res, strict_v, i, *condition);
}
