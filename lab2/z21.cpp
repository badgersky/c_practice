#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable: 4996)

int main()
{
	char c = 'a';
	int ret;

	while (c != 'e') {
		printf("Enter a character:\n");
		ret = scanf(" %c", &c);
		
		if (ret != 1) {
			printf("Invalid input");
			exit(1);
		}
	}
	printf("Character %c was entered", c);
}
