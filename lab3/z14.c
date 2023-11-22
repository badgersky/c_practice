#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 256

void find_pos(char c, const char *line_p, int *i);
void delete_character(const int *i, char *line_p);

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
        printf("Character %c not in text\n", c);
        exit(2);
    }

    printf("\nDeleting %c from %s\n", c, line);
    delete_character(&i, line_p);
    printf("Result:\n");
    printf("%s", line);
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

void delete_character(const int *i, char *line_p) {
    char *tmp = line_p + *i;
    *tmp = 0;
    strcat(line_p, &line_p[*i + 1]);
}
