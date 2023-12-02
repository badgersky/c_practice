#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 256
#define MAX_LINES 200

void print_text_arr(char *arr[]);

int create_text_array(char *arr[]);

void insert_line(char *arr[], int len, char *line, int index);

int main() {
    char *arr[MAX_LINES], *text = NULL, input[LINE_LEN];
    int index, ret, len;
    len = create_text_array(arr);

    printf("Enter line you want to insert:\n");
    fgets(input, LINE_LEN, stdin);
    text = (char *) malloc(strlen(input) * sizeof(char));
    if (!text) {
        printf("Memory error");
        exit(1);
    }
    strcpy(text, input);

    printf("Enter after which line you want to insert your input (max - %d):\n", len);
    ret = scanf("%d", &index);
    if (ret != 1 || index > len) {
        printf("Invalid input");
        exit(1);
    }

    insert_line(arr, len, text, index);
    print_text_arr(arr);
}

void insert_line(char *arr[], int len, char *line, int index) {
    int i = len;
    while (i >= index) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[index] = line;
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