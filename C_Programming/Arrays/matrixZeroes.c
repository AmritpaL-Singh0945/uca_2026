#include <stdio.h>
#include <stdlib.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    int firstRowZero = 0;
    int firstColZero = 0;

    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = 1;
            break;
        }
    }

    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = 1;
            break;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (firstColZero) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }

    if (firstRowZero) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }
}

void printMatrix(int** matrix, int m, int n) {
    printf("[\n");
    for (int i = 0; i < m; i++) {
        printf(" [");
        for (int j = 0; j < n; j++) {
            printf("%d", matrix[i][j]);
            if (j < n - 1) printf(",");
        }
        printf("]\n");
    }
    printf("]\n");
}

int main() {
    int row1_0[] = {1, 1, 1};
    int row1_1[] = {1, 0, 1};
    int row1_2[] = {1, 1, 1};
    int* matrix1[] = {row1_0, row1_1, row1_2};
    int colSize1 = 3;

    printf("Example 1 Output:\n");
    setZeroes(matrix1, 3, &colSize1);
    printMatrix(matrix1, 3, colSize1);

    int row2_0[] = {0, 1, 2, 0};
    int row2_1[] = {3, 4, 5, 2};
    int row2_2[] = {1, 3, 1, 5};
    int* matrix2[] = {row2_0, row2_1, row2_2};
    int colSize2 = 4;

    printf("\nExample 2 Output:\n");
    setZeroes(matrix2, 3, &colSize2);
    printMatrix(matrix2, 3, colSize2);

    return 0;
}