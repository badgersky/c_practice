#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma warning (disable: 4996)

double calc(double x, double y, int* num);

int main()
{
	double x, y, res;
	int ret, num;
	printf("Enter two numbers:\n");
	ret = scanf("%lf%lf", &x, &y);

	if (ret != 2) {
		printf("Invalid input\n");
		exit(1);
	}

	res = calc(x, y, &num);
	printf("Result = %lf, number of equation = %d", res, num);
}

double calc(double x, double y, int* num) {
	double res;
	if (pow(x, 2) + pow(y, 2) <= 1) {
		*num = 1;
		res = pow(x, 2) + y;
	}
	if (y > x + 5) {
		*num = 2;
		res = 2 * x + pow(y, 2);
	}
	if (pow(x, 2) + pow(y, 2) > 1 && y <= x + 5) {
		*num = 3;
		res = pow(x, 2) / 2 + y;
	}
	return res;
}