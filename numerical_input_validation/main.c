#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_LINE 256

int count_words(const char *str);
char *messages(int index);
int validate_input_characters(char *str);
void print_message(int x, int y, int z, int w);
int validate_input_numbers(char * str);
void save_to_file(char *str);
int check_int_size(char *str);

int main() {
    char input[MAX_LINE], *str;
    int char_check, words_check, number_check, size_check, active = 1;

    while (active) {
        printf("Enter exactly three integer separated by spaces:\n");

        fgets(input, sizeof(input), stdin);
        str = (char *)malloc(sizeof(char) * strlen(input));
        if (strchr(input, '\n') == NULL) {
            printf("Input is too long");
            exit(1);
        }
        if (!str) {
            printf("Memory allocation error");
            exit(1);
        }
        strcpy(str, input);

        char_check = validate_input_characters(str);
        words_check = count_words(str);
        number_check = validate_input_numbers(str);
        size_check = check_int_size(str);
        print_message(char_check, words_check, number_check, size_check);

        if (char_check == 1 && words_check == 3 && number_check == 0 && size_check == 0) {
            save_to_file(str);
            active = 0;
        }
    }

    if (str) {
        free(str);
        str = NULL;
    }

    printf("Success\n");
}

void print_message(int x, int y, int z, int w) {
    if (x == 0) {
        printf("%s", messages(x));
    }
    if (y != 3) {
        printf("%s", messages(y));
    }
    if (z == 3) {
        printf("%s", messages(z));
    }
    if (w == 4) {
        printf("%s", messages(w));
    }
    printf("\n");
}

char *messages(int index) {
    char *messages[] = {
            "Invalid input characters\n",
            "Too many input values\n",
            "Too few input values\n",
            "Numbers cannot start with 0\n",
            "One or more integers exceeds integer limit\n",
    };
    return messages[index];
}

int validate_input_numbers(char * str) {
    char a = ' ', b = *str, c = *(str + 1);

    while (b != '\0') {
        if (b == 48) {
            if (a == 32 || a == 45 || a == 9 || a == 43) {
                if (c != 32 && c != 10 && c != 9) {
                    return 3;
                }
            }
        }
        str++;
        a = b; b = *str; c = *(str + 1);
    }
    return 0;
}

int validate_input_characters(char *str) {
    char a = *str;
    int res = 1;
    while (*str != 10) {
        if (a > 47 && a < 58) {
            if (*str == 45 || *str == 43) {
                res = 0;
                break;
            }
        }
        if (*str == 32 || *str == 45 || *str == 9 || *str == 43) {
            a = *str;
            str++;
            continue;
        }
        if (*str < 48 || *str > 57) {
            res = 0;
            break;
        }
        a = *str;
        str++;
    }
    return res;
}

int count_words(const char *str) {
    int count = 0, in_word = 1;
    while (*str == 32 || *str == 9) {
        str++;
    }

    while (*str != 0 && *str != 10) {
        if (*str == 32 || *str == 9) {
            if (in_word) {
                count++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
        str++;
    }
    if (in_word) {
        count++;
    }

    if (count > 3) {
        return 1;
    } else if (count < 3) {
        return 2;
    }
    return count;
}

int check_int_size(char *str) {
    char *endptr;

    while (*str != 0 && *str != 10) {
        if (*str < 48 || *str > 57) {
            str++;
        }
        if (*str == 45 || *str == 43 || *str == 9) {
            str++;
        } else {
            long num = strtol(str, &endptr, 10);
            if (num == LONG_MAX || num == LONG_MIN) {
                return 4;
            }
            str = endptr;
        }
    }
    return 0;
}

void save_to_file(char *str) {
    FILE *file;
    file = fopen("results", "w");
    if (!file) {
        printf("Error while opening file");
        exit(1);
    }
    fprintf(file, "%s", str);
    fclose(file);
}
