#include<stdio.h>
#include<stdlib.h>

#pragma warning (disable: 4996)

int main() {
	FILE* fp = NULL;
	fp = fopen("z27.txt", "r");
	if (fp == NULL) {
		printf("Unable to open file\n");
		exit(1);
	}
	
	char c;
	while (1) {
		fscanf(fp, "%c", &c);

		if (c == '\n') {
			break;
		}

		printf(" %c", c);
	}
}