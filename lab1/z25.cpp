#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>

#pragma warning (disable: 4996)

int rectangle()
{
	double a, b;
	int ret = -1;
	double tol = 1e-14;
	printf("Enter both lengths of rectangle`s sides\n");
	ret = scanf("%lf%lf", &a, &b);

	if (ret != 2) {
		printf("Error while loading data\n");
		return 0;
	}

	if (a * b <= tol) {
		printf("Invalid input\n");
		return 0;
	}

	double area = a * b;
	double d = 2 * a + 2 * b;
	printf("Area: %lf\n", area);
	printf("Circuit: %lf\n", d);
	return 1;
}

int square()
{
	double a;
	int ret = -1;
	double tol = 1e-14;
	printf("Enter length of square`s side\n");
	ret = scanf("%lf", &a);

	if (ret != 1) {
		printf("Error while loading data\n");
		return 0;
	}

	if (a <= tol) {
		printf("Invalid input\n");
		return 0;
	}

	double area = pow(a, 2);
	double d = 4 * a;
	printf("Area: %lf\n", area);
	printf("Circuit: %lf\n", d);
	return 1;
}
	
int triangle()
{
	double a, b, c;
	int ret = -1;
	double tol = 1e-14;

	printf("Enter all lengths of triangle`s sides\n");
	ret = scanf("%lf%lf%lf", &a, &b, &c);

	if (ret != 3) {
		printf("Error while loading data\n");
		return 0;
	}

	if (a * b * c <= tol) {
		printf("Invalid input\n");
		return 0;
	}

	int con1 = (a - (b + c)) > tol;
	int con2 = (b - (c + a)) > tol;
	int con3 = (c - (a + b)) > tol;
	if (con1 || con2 || con3) {
		printf("Invalid input\n");
		return 0;
	}

	double d = a + b + c;
	double p = d / 2;
	double area = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("Area: %lf\n", area);
	printf("Circuit: %lf\n", d);
	return 1;
}

int circle()
{
	double r;
	double tol = 1e-14;
	int ret = -1;

	printf("Enter circle`s radius\n");
	ret = scanf("%lf", &r);

	if (ret != 1) {
		printf("Error while loading data\n");
		return 0;
	}

	if (r <= tol) {
		printf("Invalid input\n");
		return 0;
	}

	double area = pow(r, 2) * M_PI;
	double d = M_PI * 2 * r;
	printf("Area: %lf\n", area);
	printf("Circuit: %lf\n", d);
	return 1;
}

int main()
{	
	printf("-------- RECTANGLE --------\n");
	rectangle();
	printf("\n--------- SQUARE ---------\n");
	square();
	printf("\n--------- TRIANGLE ---------\n");
	triangle();
	printf("\n--------- CIRCLE -----------\n");
	circle();
}