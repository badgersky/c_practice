#include <stdio.h>
#include <stdlib.h>

void validate_input(int ret);
void move_array(int arr[], int len);
void print_array(int arr[], int n);

int main()
{
    int n, ret;

    printf("Enter array`s length:\n");
    ret = scanf("%d", &n);
    validate_input(ret);

    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("Enter %d number of array:\n", i + 1);
        ret = scanf("%d", &arr[i]);
        validate_input(ret);
    }

    printf("Before change:\n");
    print_array(arr, n);
    move_array(arr, n);
    printf("\nAfter change:\n");
    print_array(arr, n);
}

void validate_input(int ret) {
    if (ret != 1) {
        printf("invalid input");
        exit(2);
    }
}

void move_array(int arr[], int len) {
    int tmp = arr[len - 1];
    for (int i = len - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = tmp;
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
}
