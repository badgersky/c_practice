#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma warning (disable: 4996)

void validate_n_m(int const *np, int const *mp, int ret);
int validate_a_b_epx(double *a, double *b, double const *eps, int ret, double const *err);
void series(double x, int m, double eps, int *condition, FILE *f);

int main() {
    int n, m, ret, condition;
    double a, b, eps, dx, x, err = 1e-14;
    FILE *file = NULL;

    printf("Enter n, m:\n");  //m n input and validation
    ret = scanf("%d %d", &n, &m);
    validate_n_m(&n, &m, ret);

    printf("Enter a, b - endpoints of interval, and eps - accuracy:\n");  //a b eps input and validation
    ret = scanf("%lf %lf %lf", &a, &b, &eps);
    if (validate_a_b_epx(&a, &b, &eps, ret, &err) == 0) {
        printf("Invalid input");
        exit(2);
    }

    file = fopen("results", "w");
    if (!file) {
        printf("File not open");
        exit(2);
    }

    if (fabs(a - b) <= err) {
        series(a, m, eps, &condition, file);
        fclose(file);
        exit(0);
    }

    dx = (b - a) / n;
    x = a;
    while (x <= b) {
        series(x, m, eps, &condition, file);
        x += dx;
    }

    fclose(file);
}

void validate_n_m(int const *np, int const *mp, int ret) {
    if (*np * (*mp) <= 0 || ret != 2) {
            printf("Invalid input");
            exit(2);
    }
}

int validate_a_b_epx(double *a, double *b, double const *eps, int ret, double const *err) {
    if (ret != 3) {
        return 0;
    }
    if (*a > *b) {
        double z = *b;
        *b = *a;
        *a = z;
    }
    if (fabs(*a + 1.) < *err || fabs(*b - 1.) < *err) {
        return 0;
    }
    if (*eps <= *err) {
        return 0;
    }
    return 1;
}

void series(double x, int m, double eps, int *condition, FILE *f) {
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

    fprintf(f, "|\t%lf\t|\t%lf\t|\t%lf\t|\t%d\t|\t%d\t|\n", x, res, strict_v, i, *condition);
    printf("|\t%lf\t|\t%lf\t|\t%lf\t|\t%d\t|\t%d\t|\n", x, res, strict_v, i, *condition);
}
