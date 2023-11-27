#include <stdio.h>

#define MAX_LINE 256

int count_words(const char *str);
char *messages(int index);
int validate_input_characters(char *str);
void print_message(int x, int y);

int main() {
    char input[MAX_LINE], *str;
    int char_check, words_check, active = 1;

    while (active) {
        printf("Enter exactly three integer separated by spaces\n");
        str = fgets(input, sizeof(input), stdin);
        char_check = validate_input_characters(str);
        words_check = count_words(str);
        print_message(char_check, words_check);

        if (char_check == 1 && words_check == 3) {
            active = 0;
        }
    }

    printf("\nSuccess\n");
}

void print_message(int x, int y) {
    if (x == 0) {
        printf("%s", messages(x));
    }
    if (y != 3) {
        printf("%s", messages(y));
    }
    printf("\n");
}

char *messages(int index) {
    char *messages[] = {
            "invalid input characters\n",
            "to many input values\n",
            "to few input values\n",
            "Enter input:\n"
    };
    return messages[index];
}

int validate_input_characters(char *str) {
    char a = *str;
    int res = 1;
    while (*str != '\n') {
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

    while (*str != '\0' && *str != '\n') {
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
