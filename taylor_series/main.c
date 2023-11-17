#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma warning (disable: 4996)

void validate_n_m(int const *np, int const *mp, int ret);
int validate_a_b_epx(double *a, double *b, double const *eps, int ret);

int main() {
    int n, m, ret, ab_check;
    double a, b, eps;

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
    printf("%lf %lf", a, b);
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
