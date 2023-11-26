#include <stdio.h>

#define MAX_LINE 256

int count_words(const char *str);
char *display_message(int condition);
int validate_input(char *str);
void define_condition(int *con, int check, int words_num);

int main() {
    char input[MAX_LINE], *str;
    int check, words_num, condition = 5;

    while (condition != 2137) {
        printf("Enter exactly three integer separated by spaces\n");
        printf("%s", display_message(condition));
        str = fgets(input, sizeof(input), stdin);
        check = validate_input(str);
        words_num = count_words(str);
        define_condition(&condition, check, words_num);
    }

    printf("\nSuccess\n");
}

void define_condition(int *con, int check, int words_num) {
    if (check == 0 && words_num > 3) {
        *con = 0;
    } else if (check == 0 && words_num < 3) {
        *con = 1;
    } else if (check == 0 && words_num == 3) {
        *con = 2;
    } else if (check == 1 && words_num > 3) {
        *con = 3;
    } else if (check == 1 && words_num < 3) {
        *con = 4;
    } else {
        *con = 2137;
    }
}

char *display_message(int condition) {
    char *messages[] = {
            "invalid input, too many words\n",
            "invalid input, too few words\n",
            "invalid input\n",
            "to many words\n",
            "to few words\n",
            "Enter input:\n"
    };
    return messages[condition];
}

int validate_input(char *str) {
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

    while (*str != '\0') {
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

    return count;
}
