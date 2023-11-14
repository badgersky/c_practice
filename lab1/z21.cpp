#include <stdio.h>
#include <math.h>
# pragma warning (disable: 4996)

void calculations(double x, double y, double z, int k, int m)
{
	double w1, w2, w3, w4, w5, w6;
	w1 = pow((x / (y * z)), 1 / 3.) * log(x * x + y * y);
	w2 = sin(k * (x / 2)) * cos(m * y) + y * exp(2 * x - 1);
	w3 = fabs(x / (2 * pow(y, 2) + 1)) + sqrt(y / (pow(z, 2) + 3)) + 5 * pow((y + z), 3);
	w4 = (x / (y * z)) * pow((z + 1), 1 / 3.) + pow((pow(x, 2) + pow(z, 2) + 1), 1. / k) - fabs(y);
	w5 = 1 / sqrt(pow(x, 2) + pow(y, 2) + pow(k, 2.)) + 1 / x * sin(k * y);

	printf("%.8lf\n", w1);
	printf("%.8lf\n", w2);
	printf("%.8lf\n", w3);
	printf("%.8lf\n", w4);
	printf("%.8lf\n", w5);
}

int main()
{
	// user input
	double x, y, z;
	int k, m;
	int ret = -1;

	printf("Enter 3 decimal numbers\n");
	ret = scanf("%lf %lf %lf", &x, &y, &z);

	printf("Enter 2 integer numbers\n");
	ret = scanf("%d %d", &k, &m);

	printf("\nCalculations for user input\n");
	calculations(x, y, z, k, m);
	
	printf("\nCalculations for numbers given in task description\n");
	x = 3.14;
	y = 12.56;
	z = 7;
	k = 2;
	m = 4;
	calculations(x, y, z, k, m);

}
