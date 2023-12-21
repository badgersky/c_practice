#include <bits/types/FILE.h>
#include <stdio.h>
#include <stdlib.h>

extern int ** allocate_matrix1(int n, int m);
extern int ** allocate_matrix2(int n, int m);
extern int * allocate_vector(int m);
extern void free_memory1(int **matrix, int n);
extern void free_memory2(int **matrix, int *tab);
extern void free_vector(int *vector);
extern void read_matrix(FILE *fd, int**matrix, int n, int m);
extern void read_vector(FILE *fd, int*vector, int m);
extern int** sum_matrices(int**ma1, int**ma2, int n, int m);
extern int** matrix_x_matrix(int**ma1, int**ma2, int n, int m);
extern int* vector_x_matrix(int**ma, int*ve, int n, int m);
extern void write_matrix(FILE *fw, int**matrix, int n, int m);
extern void write_vector(FILE *fw, int*vector, int m);

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
