#include <math.h>
#include <stdio.h>

#pragma warning (disable: 4996)

int main()
{
	double a, b, c;
	int ret = -1;

	printf("----- program calculates roots of quadratic equation ----\n");
	printf("Enter a, b and c\n");
	ret = scanf("%le%le%le", &a, &b, &c);
	printf("\n");
	
	if (ret != 3) {
		printf("Error while loading data\n");
		printf("loaded data: a = %e b = %e c = %e", a, b, c);
		return 0;
	}

	double tol = 1e-8;
	if (a <= tol) {
		printf("That is not quadratic equation\n");
		return 0;
	}

	printf("Quadratic equation: %.2lfx^2 + %.2lfx + %.2f\n", a, b, c);

	double D = -1;
	D = pow(b, 2) - 4 * a * c;
	if (D < 0.0) {
		printf("No roots in real numbers, D = %f < 0\n", D);
		
		double r1, r2, u1, u2;
		r1 = -(b / (2 * a));
		u1 = sqrt(fabs(pow(-r1, 2) - c / a));
		r2 = r1;
		u2 = -u1;
		printf("Roots in imaginary numbers: %.2f + i%.2f\tand\t%.2f + i%.2f\n", r1, u1, r2, u2);
		return 0;
	}

	double p1, p2, x1, x2;
	p1 = -b / (2. * a);
	p2 = sqrt(D) / (2. * a);
	x1 = p1 + p2;
	x2 = p1 - p2;

	printf("Roots in real numbers: x1 = %.2f\tx2 = %.2f\n", x1, x2);
	printf("---------------------------------------------------------");
	return 0;
}