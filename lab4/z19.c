#include <stdio.h>
#include <stdlib.h>

int **allocate_matrix1(int n, int m);

int **allocate_matrix2(int n, int m);

void free_memory1(int **matrix, int n);

void free_memory2(int **pointers, int *tab);

int **sum_matrices(int **ma1, int **ma2, int n, int m);

void free_vector(int *vector);

int *allocate_vector(int m);

void read_matrix(FILE *fd, int **matrix, int n, int m);

void write_matrix(FILE *fw, int **matrix, int n, int m);

void write_vector(FILE *fw, int *vector, int m);

int *vector_x_matrix(int **ma, const int *ve, int n, int m);

void read_vector(FILE *fd, int *vector, int m);

int **matrix_x_matrix(int **ma1, int **ma2, int n, int m);

int main() {
    FILE *fd, *fw;
    int n, m;

    fd = fopen("data", "r");
    fw = fopen("results", "w");
    if (!fd || !fw) {
        printf("file error");
        exit(1);
    }

    fscanf(fd, "%d %d", &n, &m);
    int **matrix1 = allocate_matrix1(n, m), **matrix2 = allocate_matrix2(n, m);
    int *vector = allocate_vector(m);
    read_matrix(fd, matrix1, n, m);
    read_matrix(fd, matrix2, n, m);
    read_vector(fd, vector, m);

    int **matrix3 = sum_matrices(matrix1, matrix2, n, m);
    int *res_ve = vector_x_matrix(matrix1, vector, n, m);
    int **matrix4 = matrix_x_matrix(matrix1, matrix2, n, m);

    fprintf(fw, "sum of matrix2 and matrix1:\n");
    printf("sum of matrix2 and matrix1:\n");
    write_matrix(fw, matrix3, n, m);
    write_matrix(stdout, matrix3, n, m);
    fprintf(fw, "\nproduct of matrix1 and matrix2:\n");
    printf("\nproduct of matrix1 and matrix2:\n");
    write_matrix(fw, matrix4, n, m);
    write_matrix(stdout, matrix4, n, m);
    fprintf(fw, "\nproduct of vector and matrix1:\n");
    printf("\nproduct of vector and matrix1:\n");
    write_vector(fw, res_ve, m);
    write_vector(stdout, res_ve, m);

    free_memory1(matrix1, n);
    free_memory2(matrix2, matrix2[0]);
    free_vector(vector);
}

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

int **sum_matrices(int **ma1, int **ma2, int n, int m) {
    int **ma3 = allocate_matrix1(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ma3[i][j] = ma1[i][j] + ma2[i][j];
        }
    }
    return ma3;
}

int *vector_x_matrix(int **ma, const int *ve, int n, int m) {
    int *result = allocate_vector(m), part_res;

    for (int i = 0; i < n; i++) {
        part_res = 0;
        for (int j = 0; j < m; j++) {
            part_res += ve[j] * ma[i][j];
        }
        result[i] = part_res;
    }

    return result;
}

int **matrix_x_matrix(int **ma1, int **ma2, int n, int m) {
    int **p_matrix = allocate_matrix1(n, m);
    for (int i = 0; i < m; i++) {
        for (int k =0; k < m; k++) {
            for (int j = 0; j < m; j++) {
                p_matrix[i][j] = p_matrix[i][j] + ma1[i][k] * ma2[k][j];
            }
        }
    }
    return p_matrix;
}
