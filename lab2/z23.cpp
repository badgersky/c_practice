#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable: 4996)

int main()
{
	char c = 'a';
	int ret, na = 0, nb = 0, nc = 0, nall = 0;

	while (1) {
		printf("Enter a character:\n");
		ret = scanf(" %c", &c);

		if (ret != 1) {
			printf("Invalid input");
			exit(1);
		}

		if (c == 'e') {
			break;
		}
		if (c == 'a') {
			na++;
			continue;
		}
		if (c == 'b') {
			nb++;
			continue;
		}
		if (c == 'c') {
			goto c_occur;
			continue;
		}

		nall += 1;

		c_occur: (nc++, nall++);
	}

	printf("Character %c was entered\n", c);
	printf("Number of occurences of characters:\n");
	printf("a : %d\n", na);
	printf("b : %d\n", nb);
	printf("c : %d\n", nc);
	printf("other characters: %d\n", nall);
}