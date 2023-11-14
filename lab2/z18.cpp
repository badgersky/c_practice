#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable: 4996)

int main() {
	int n, ret, i;
	printf("Enter a number:\n");
	ret = scanf("%d", &n);

	if (ret != 1 || n <= 0) {
		printf("Invalid input\n");
		exit(1);
	}

	for (i = 0; i < n; i++) {
		printf("Hello world!\n");
	}
}