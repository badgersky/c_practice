#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#pragma warning (disable: 4996)

double ff(double x);

int main() {
	double a, b, dx, x, y;
	int ret;
	printf("Enter a, b and dx:\n");
	ret = scanf("%lf%lf%lf", &a, &b, &dx);

	if (ret != 3) {
		printf("Invalid input");
		exit(1);
	}

	FILE* fw = NULL;
	fw = fopen("z29.txt", "w");

	x = a;
	while (x <= b) {
		y = ff(x);
		printf("\t%10.2lf\t\t%15.4lf\n", x, y);
		fprintf(fw, "\t%10.2lf\t\t%15.4lf\n", x, y);
		x += dx;
	}
	fclose(fw);
}

double ff(double x) {
	return (1 / (pow(x, 2) + sqrt(1 + 2 * x + 3 * pow(x, 2))));
}
