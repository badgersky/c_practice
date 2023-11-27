#include <stdio.h>

#define MAX_LINE 256

int count_words(const char *str);
char *messages(int index);
int validate_input_characters(char *str);
void print_message(int x, int y, int z);
int validate_input_numbers(char * str);

int main() {
    char input[MAX_LINE], *str;
    int char_check, words_check, number_check, active = 1;

    while (active) {
        printf("Enter exactly three integer separated by spaces:\n");
        str = fgets(input, sizeof(input), stdin);
        char_check = validate_input_characters(str);
        words_check = count_words(str);
        number_check = validate_input_numbers(str);
        print_message(char_check, words_check, number_check);

        if (char_check == 1 && words_check == 3 && number_check == 0) {
            active = 0;
        }
    }

    printf("Success\n");
}

void print_message(int x, int y, int z) {
    if (x == 0) {
        printf("%s", messages(x));
    }
    if (y != 3) {
        printf("%s", messages(y));
    }
    if (z == 3) {
        printf("%s", messages(z));
    }
    printf("\n");
}

char *messages(int index) {
    char *messages[] = {
            "invalid input characters\n",
            "too many input values\n",
            "too few input values\n",
            "numbers cannot start with 0\n",
    };
    return messages[index];
}

int validate_input_numbers(char * str) {
    char a = ' ', b = *str, c = *(str + 1);

    while (b != '\0') {
        if (b == 48) {
            if (a == 32 || a == 45) {
                if (c != 32 && c != 10) {
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
            if (*str == '-') {
                res = 0;
            }
        }
        if (*str == 32 || *str == 45) {
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
    while (*str == 32) {
        str++;
    }

    while (*str != 0 && *str != 10) {
        if (*str == 32) {
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
