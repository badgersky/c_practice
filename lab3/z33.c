#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 256
#define MAX_LINES 200

int create_text_array(char *arr[]);

char * get_word();

void print_text_arr(char *arr[]);

void search_text(char *arr[], const char *word, char *result[]);

int main() {
    char *arr[MAX_LINES], *word, *result[MAX_LINES];
    create_text_array(arr);
    word = get_word();
    search_text(arr, word, result);
    print_text_arr(result);
}

char * get_word() {
    char input[LINE_LEN], *word = NULL;
    printf("\nEnter word you want to find at the beginning of the lines\n");
    fgets(input, LINE_LEN, stdin);
    word = (char *) malloc((strlen(input) + 1) * sizeof(char));
    if (!word) {
        printf("Memory error");
        exit(1);
    }
    strcpy(word, input);
    return word;
}

void search_text(char *arr[], const char *word, char *result[]) {
    int i = 0, x, okay, a = 0;

    while (arr[i]) {
        x = 0, okay = 1;
        while (word[x] != 10 && word[x] != 0) {
            if (word[x] != arr[i][x]) {
                okay = 0;
                break;
            }
            x++;
        }
        if (okay) {
            result[a] = arr[i];
            a++;
        }
        i++;
    }
}

void print_text_arr(char *arr[]) {
    int i = 0;
    while (arr[i]) {
        printf("%s", arr[i]);
        i++;
    }
}

int create_text_array(char *arr[]) {
    char input[LINE_LEN];
    int i = 0;
    FILE *file;
    file = fopen("DANE.txt", "r");
    if (!file) {
        printf("File opening error");
        exit(1);
    }

    while (fgets(input, LINE_LEN, file)) {
        arr[i] = (char *) malloc((strlen(input) + 1) * sizeof(char));
        if (!arr[i]) {
            printf("Memory error");
            exit(1);
        }
        strcpy(arr[i], input);
        i++;
    }
    arr[i] = NULL;
    return i;
}