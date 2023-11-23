#include <stdlib.h>
#include <stdio.h>

#define MAX_LINE 256

void exchange_characters(char *line_p, char c1, char c2);

int main()
{
    char line[MAX_LINE], *line_p, c1, c2;
    int ret;

    printf("Enter text:\n");
    line_p = gets(line);

    printf("Enter characters to exchange:\n");
    ret = scanf("%c %c", &c1, &c2);
    if (ret != 2) {
        printf("Invalid input\n");
        exit(2);
    }

    exchange_characters(line_p, c1, c2);
    printf("%s", line_p);
}

void exchange_characters(char *line_p, char c1, char c2) {
    while (*line_p != '\0') {
        if (*line_p == c1) {
            *line_p = c2;
        }
        line_p++;
    }
}