#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

void join_strings(char *p1, char *p2, int i);
void validate(int ret, int i, int len);

int main()
{
    char line1[MAX_LINE], line2[MAX_LINE], *line1_p, *line2_p;
    int i, len, ret;
    printf("Enter first line:\n");
    line1_p = gets(line1);
    printf("Enter second line:\n");
    line2_p = gets(line2);

    printf("Enter index:\n");
    ret = scanf("%d", &i);
    len = strlen(line2); // NOLINT(*-narrowing-conversions)
    validate(ret, i, len);

    join_strings(line1_p, line2_p, i);
    printf("Result:\n");
    printf("%s", line1);
}

void join_strings(char *p1, char *p2, int i) {
    strcat(p1, p2 + i);
}

void validate(int ret, int i, int len) {
    if (ret != 1 || i > len) {
        printf("Invalid input");
        exit(2);
    }
}
