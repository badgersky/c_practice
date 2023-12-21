extern int **allocate_matrix1(int n, int m);

extern int *allocate_vector(int m);

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
        for (int k = 0; k < m; k++) {
            for (int j = 0; j < m; j++) {
                p_matrix[i][j] = p_matrix[i][j] + ma1[i][k] * ma2[k][j];
            }
        }
    }
    return p_matrix;
}