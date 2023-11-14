#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable: 4996)

void change(int* x, int* y);

int main() 
{
	int x, y, ret;
	printf("Enter two integers:\n");
	ret = scanf("%d%d", &x, &y);

	if (ret != 2) {
		printf("Invalid input");
		exit(1);
	}

	printf("Numbers before change: x = %d, y = %d\n", x, y);
	change(&x, &y);
	printf("Numbers after change: x = %d, y = %d\n", x, y);
}

void change(int* x, int* y) {
	int z = *x;
	*x = *y;
	*y = z;
}