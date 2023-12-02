#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 256

void input_text(char **str);

int swap_spaces(char *str);

char *get_word(char *str, int index);

int main() {
    char *str = NULL, *word = NULL;
    int i, ret, len;
    input_text(&str);
    printf("%s\n", str);
    len = swap_spaces(str);

    printf("Enter position of word you want to display:\n");
    ret = scanf("%d", &i);
    if (ret != 1 || i < 1 || i > len) {
        printf("Invalid input\n");
        exit(1);
    }

    word = get_word(str, i);
    printf("%s\n", word);

    if (str) {
        free(str);
        str = NULL;
    }
    if (word) {
        free(word);
        word = NULL;
    }

}

void input_text(char **str) {
    char input[LINE_LEN];
    printf("Enter short sentence (max %d characters)\n", LINE_LEN);
    fgets(input, LINE_LEN, stdin);
    *str = (char *) malloc((strlen(input) + 1) * sizeof(char));
    if (!*str) {
        printf("Memory error");
        exit(1);
    }
    strcpy(*str, input);
}

int swap_spaces(char *str) {
    int res = 1;
    while (*str != 0) {
        if (*str == 32) {
            *str = ':';
            res++;
        }
        str++;
    }
    return res;
}

char *get_word(char *str, int index) {
    int col_num = 1, i = 0;
    char word[LINE_LEN] = "", *wp;
    while (*str != 0) {
        if (col_num == index) {
            if ((*str >= 65 && *str <= 90) || (*str >= 97 && *str <= 122)) {
                word[i] = *str;
                i++;
            }
        }
        if (*str == ':') {
            col_num++;
        }
        str++;
    }

    word[i] = 0;
    wp = (char *) malloc((strlen(word) + 1) * sizeof(char));
    strcpy(wp, word);
    return wp;
}
