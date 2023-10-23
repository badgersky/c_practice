#include <stdio.h>
#include <math.h>

#pragma warning (disable: 4996)

int main()
{
	int a, b, c, d;
	int ret = -1;
	printf("Enter three integer numbers\n");
	ret = scanf("%d%d%d%d", &a, &b, &c, &d);
	int biggest = a;

	if (ret != 4) {
		printf("Error while loading data\n");
		return 0;
	}

	if (a >= b && a >= c && a >= d) {
		biggest = a;
		printf("biggest number: %d\n", a);
		printf("position: 1");
	}
	else if (b >= a && b >= c && b >= d) {
		biggest = c;
		printf("biggest number: %d\n", c);
		printf("position: 3");
	}
	else if (c >= b && c >= d && c >= a) {
		biggest = b;
		printf("biggest number: %d\n", b);
		printf("position: 2");
	}
	else if (d >= a && d >= b && d >= c) {
		biggest = d;
		printf("biggest number: %d\n", d);
		printf("position: 4");
	}

	return biggest;
}