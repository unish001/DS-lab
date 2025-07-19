#include <stdio.h>

// Recursive function to calculate factorial
int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

// Recursive function to calculate nCr
int combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Function to print Pascal's Triangle
void pascalTriangle(int rows) {
    for (int i = 0; i < rows; i++) {
        // Print spaces for alignment
        for (int space = 0; space < rows - i - 1; space++) {
            printf("  ");
        }
        // Print values
        for (int j = 0; j <= i; j++) {
            printf("%4d", combination(i, j));
        }
        printf("\n");
    }
}

int main() {
    int rows;
    printf("Enter number of rows for Pascal's Triangle: ");
    scanf("%d", &rows);

    printf("Pascal's Triangle:\n");
    pascalTriangle(rows);

    return 0;
}
