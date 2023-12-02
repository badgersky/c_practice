#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 256
#define MAX_LINES 200

int create_text_array(char *arr[]);

void validate_input(int ret, int x, int y, int len);

void swap_lines(char *arr[], int x, int y);

void print_text_arr(char *arr[]);

void free_memory(char *arr[], int len);

int main() {
    int len, ret, x, y;
    char *arr[MAX_LINES];
    len = create_text_array(arr);
    print_text_arr(arr);
    printf("\nEnter positions of lines to swap places, numbers must be in interval 1 - %d\n", len);
    ret = scanf("%d %d", &x, &y);
    x--, y--;
    validate_input(ret, x, y, len);
    swap_lines(arr, x, y);
    print_text_arr(arr);
    free_memory(arr, len);
}

void free_memory(char *arr[], int len) {
    for (int i = 0; i <= len; i++) {
        if (arr[i]) {
            free(arr[i]);
        }
    }
}

void print_text_arr(char *arr[]) {
    int i = 0;
    while (arr[i]) {
        printf("%s", arr[i]);
        i++;
    }
}

void swap_lines(char *arr[], int x, int y) {
    char *tmp = arr[x];
    arr[x] = arr[y];
    arr[y] = tmp;
}

void validate_input(int ret, int x, int y, int len) {
    len--;
    if (ret != 2) {
        printf("Error while loading from stdin");
        exit(1);
    }
    if (x < 0 || x > len) {
        printf("Invalid input");
        exit(1);
    }
    if (y < 0 || y > len) {
        printf("Invalid input");
        exit(1);
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