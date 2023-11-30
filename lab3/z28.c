#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 256

void count_characters(const char *str, int *cap, int *lower, int *other);

int main() {
    char input[LINE_LEN], *str;
    int cap, lower, other, i = 1;
    FILE *file = NULL;
    file = fopen("DANE.txt", "r");
    if (!file) {
        printf("Error while opening file");
        exit(1);
    }

    while (fgets(input, LINE_LEN, file)) {
        str = (char *)malloc((strlen(input) + 1) * sizeof(char));
        if (!str) {
            printf("Memory error");
            exit(1);
        }
        strcpy(str, input);

        count_characters(str, &cap, &lower, &other);
        printf("line: %d\tuppercase: %d\tlowercase: %d\tother: %d\n", i, cap, lower, other);
        i += 1;
        free(str);
    }
    fclose(file);
}

void count_characters(const char *str, int *cap, int *lower, int *other) {
    *cap = 0, *lower = 0, *other = 0;
    while (*str != 0) {
        if (*str >= 65 && *str <= 90) {
            *cap += 1;
        } else if (*str >= 97 && *str <= 122) {
            *lower += 1;
        } else {
            *other += 1;
        }
        str++;
    }
}
