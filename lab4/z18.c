#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fd, *fw;
    int m, n, sum1, sum2, **matrix_a, **matrix_b, **sum_matrix, *vector, *vector_p;
    fd = fopen("data", "r");
    fw = fopen("results", "w");
    fscanf(fd, "%d %d", &n, &m);

    matrix_a = (int **) malloc(n * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrix_a[i] = (int *) malloc(m* sizeof(int));
    }

    matrix_b = (int **) malloc(n * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrix_b[i] = (int *) malloc(m* sizeof(int));
    }

    sum_matrix = (int **) malloc(n * sizeof(int*));
    for (int i = 0; i < m; i++) {
        sum_matrix[i] = (int *) malloc(m* sizeof(int));
    }

    vector = (int*) malloc(m * sizeof(int));
    vector_p = (int*) malloc(m * sizeof(int));

    printf("matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(fd, "%d", &matrix_a[i][j]);
            printf("%d ", matrix_a[i][j]);
        }
        printf("\n");
    }

    printf("\nmatrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(fd, "%d", &matrix_b[i][j]);
            printf("%d ", matrix_b[i][j]);
        }
        printf("\n");
    }

    printf("\nvector Y:\n");
    for (int i = 0; i < m; i++) {
        fscanf(fd, "%d", &vector[i]);
        printf("%d ", vector[i]);
    }

    printf("\n\nsum of matrices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum1 = matrix_b[i][j] + matrix_a[i][j];
            sum_matrix[i][j] = sum1;
            printf("%d ", sum1);
            fprintf(fw, "%d ", sum1);
        }
        printf("\n");
        fprintf(fw, "\n");
    }

    printf("\nproduct of matrix A and vector:\n");
    for (int i = 0; i < n; i++) {
        sum2 = 0;
        for (int j = 0; j < m; j++) {
            sum2 += matrix_a[i][j] * vector[j];
        }
        vector_p[i] = sum2;
        printf("%d ", sum2);
        fprintf(fw, "%d ", sum2);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        free(matrix_a[i]);
        free(matrix_b[i]);
        free(sum_matrix[i]);
    }
    free(matrix_a);
    free(matrix_b);
    free(sum_matrix);
    free(vector);
    free(vector_p);
}
