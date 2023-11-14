#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma warning (disable: 4996)

int natural_sum(int num);

int main()
{
	int result, n, ret;
	printf("Enter positive integer:\n");
	ret = scanf("%d", &n);

	if (ret != 1 || n <= 0) {
		printf("Invalid input");
		exit(1);
	}

	result = natural_sum(n);
	printf("Sum of first %d natural numbers is: %d", n, result);
}

int natural_sum(int num) {
	if (num > 1) {
		return (num + natural_sum(num - 1));
	}
	return 0;
}
