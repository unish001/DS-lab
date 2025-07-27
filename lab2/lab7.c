#include <stdio.h>

// Function to calculate nCr (combinations)
int factorial(int n) {
    if (n == 0) return 1;
    else return n * factorial(n - 1);
}

int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Pascal's Triangle:\n");

    for (int i = 0; i < n; i++) {
        // Print spaces for formatting
        for (int space = 0; space < n - i - 1; space++)
            printf("  ");

        // Print values in row
        for (int j = 0; j <= i; j++)
            printf("%4d", nCr(i, j));

        printf("\n");
    }

    return 0;
}
