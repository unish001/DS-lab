#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void binaryMatrixMultiplication(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], 
                               int result[][MAX_SIZE], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) 
            {
                result[i][j] ^= (mat1[i][k] & mat2[k][j]);
            }
        }
    }
}

// Function to print a matrix
void printMatrix(int mat[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;

    printf("Enter dimensions of first matrix (rows columns): ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter dimensions of second matrix (rows columns): ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Matrix multiplication not possible!\n");
        return 1;
    }

    printf("Enter elements of first matrix (0 or 1 only):\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &mat1[i][j]);
            if (mat1[i][j] != 0 && mat1[i][j] != 1) {
                printf("Invalid input! Only 0 or 1 allowed.\n");
                return 1;
            }
        }
    }

    printf("Enter elements of second matrix (0 or 1 only):\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &mat2[i][j]);
            if (mat2[i][j] != 0 && mat2[i][j] != 1) {
                printf("Invalid input! Only 0 or 1 allowed.\n");
                return 1;
            }2
        }
    }
    binaryMatrixMultiplication(mat1, mat2, result, rows1, cols1, cols2);

    printf("Result of binary matrix multiplication:\n");
    printMatrix(result, rows1, cols2);

    return 0;
}