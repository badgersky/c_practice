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
	int ret;
	while (1) {
		ret = fscanf(fp, "%c", &c);

		if (ret == -1) {
			break;
		}

		printf(" %c", c);
	}
	fclose(fp);
}