#include <stdio.h>
#include <stdlib.h>

void read_matrix(FILE *fd, int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (fscanf(fd, "%d", &matrix[i][j]) != 1) {
                printf("reading file error");
                exit(1);
            }
        }
    }
}

void read_vector(FILE *fd, int *vector, int m) {
    for (int i = 0; i < m; i++) {
        fscanf(fd, "%d", &vector[i]);
    }
}

void write_matrix(FILE *fw, int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(fw, "%d ", matrix[i][j]);
        }
        fprintf(fw, "\n");
    }
}

void write_vector(FILE *fw, int *vector, int m) {
    for (int i = 0; i < m; i++) {
        fprintf(fw, "%d ", vector[i]);
    }
}
