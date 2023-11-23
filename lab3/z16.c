#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

void join_lines(char *p1, char *p2);

int main()
{
    char line1[MAX_LINE], line2[MAX_LINE], *line1_p, *line2_p;
    printf("Enter first line:\n");
    line1_p = gets(line1);
    printf("Enter second line:\n");
    line2_p = gets(line2);

    join_lines(line1_p, line2_p);
    printf("\nJoined lines:\n");
    printf("%s\n", line1_p);
}

void join_lines(char *p1, char *p2) {
    char nl = '\n';
    strcat(p1, &nl);
    strcat(p1, p2);
}