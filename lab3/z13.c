#include <stdio.h>

#define MAX_LINE 256

void find_pos(char c, const char *line_p, int *i);

int main()
{
    char line[MAX_LINE], *line_p, c;
    int i = 0;

    printf("Enter line:\n");
    line_p = gets(line);

    printf("Enter character:\n");
    c = (char) getchar();

    find_pos(c, line_p, &i);
    if (i == -1) {
        printf("No character %c in text", c);
    } else {
        printf("Position of %c is %d", c, i);
    }
}

void find_pos(char c, const char *line_p, int *i) {
    char b;
    while ((b = *line_p) != '\0') {
        if (c == b) {
            break;
        }
        *i += 1;
        line_p++;
    }

    if (b == '\0') {
        *i = -1;
    }
}
