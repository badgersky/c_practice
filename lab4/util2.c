#include <stdlib.h>
#include <stdio.h>

int *allocate_vector(int m) {
    int *ve = (int *) malloc(sizeof(int) * m);
    if (!ve) {
        printf("memory error");
        exit(1);
    }
    return ve;
}

int **allocate_matrix1(int n, int m) {
    int **matrix;

    matrix = (int **) malloc(n * sizeof(int *));
    if (!matrix) {
        printf("memory error");
        exit(1);
    }

    for (int i = 0; i < m; i++) {
        matrix[i] = (int *) malloc(m * sizeof(int));
        if (!matrix[i]) {
            printf("memory error");
            exit(1);
        }
    }

    return matrix;
}

int **allocate_matrix2(int n, int m) {
    int **pointers, *tab;

    tab = (int *) malloc(sizeof(int) * n * m);
    if (!tab) {
        printf("memory error");
        exit(1);
    }

    pointers = (int **) malloc(sizeof(int *) * n);
    if (!pointers) {
        printf("memory error");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        pointers[i] = &tab[i * m];
    }

    return pointers;
}

void free_vector(int *vector) {
    if (vector) {
        free(vector);
        vector = NULL;
    }
}

void free_memory2(int **pointers, int *tab) {
    if (tab) {
        free(tab);
        tab = NULL;
    }

    if (pointers) {
        free(pointers);
        pointers = NULL;
    }
}

void free_memory1(int **matrix, int n) {
    if (matrix) {
        for (int i = 0; i < n; i++) {
            if (matrix[i]) {
                free(matrix[i]);
            }
        }
        free(matrix);
        matrix = NULL;
    }
}