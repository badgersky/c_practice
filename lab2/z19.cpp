#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable: 4996)

int factorial(int n);

int main() {
	int n, ret;
	printf("Enter a number:\n");
	ret = scanf("%d", &n);

	if (ret != 1 || n <= 0) {
		printf("Invalid input\n");
		exit(1);
	}

	printf("\nFactorial of %d is %d\n", n, factorial(n));
}

int factorial(int n) {
	int i, res = 1;
	for (i = 1; i <= n; i++) {
		res *= i;
	}
	return res;
}