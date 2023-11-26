#include <stdio.h>

#define MAX_LINE 256

int count_word(const char *p);
char *display_message(int condition);
int validate_input(char *p);
void define_condition(int *con, int check, int words_num);

int main() {
    char input[MAX_LINE], *p;
    int check, words_num, condition = 5;

    while (condition != 2137) {
        printf("Enter exactly three integer separated by spaces\n");
        printf("%s", display_message(condition));
        p = fgets(input, sizeof(input), stdin);
        check = validate_input(p);
        words_num = count_word(p);
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

int validate_input(char *p) {
    int res = 1;
    while (*p != '\n') {
        if (*p == 32) {
            p++;
            continue;
        }
        if (*p < 48 || *p > 57) {
            res = 0;
            break;
        }
        p++;
    }
    return res;
}

int count_word(const char *p) {
    char a = *p, b = ' ';
    int l = 0;
    while (*p != '\0') {
        if (a != ' ' && b == ' ') {
            l += 1;
        }
        a = b;
        b = *p++;
    }
    return l;
}