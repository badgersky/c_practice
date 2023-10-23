#include <stdio.h>
#include <math.h>

#pragma warning (disable: 4996)

int main()
{
	double a, b, c;
	double tol = 1e-10;
	int ret = -1;

	printf("Enter three decimal lengths of triangle`s sides\n");
	ret = scanf("%lf%lf%lf", &a, &b, &c);

	if (ret != 3) {
		printf("Error while loading data\n");
		return 0;
	}

	if (a < tol || b < tol || c < tol) {
		printf("Invalid input\n");
		return 0;
	}
	
	// checking if it`s triangle
	int con1, con2, con3;
	con1 = (a - (b + c)) > tol;
	con2 = (b - (c + a)) > tol;
	con3 = (c - (a + b)) > tol;
	if (con1 || con2 || con3) {
		printf("This is not triangle\n");
		return 0;
	}

	//calculations
	double p = (a + b + c) / 2;
	double area = sqrt(p * (p - a) * (p - b) * (p - c));
	double r = area / p;

	if ((area - 0.0) < tol) {
		printf("Triangle is degenerate\n");
	}

	printf("\n--- RESULTS ---\n");
	printf("Area: %lf\n", area);
	printf("Radius: %lf\n", r);
}
