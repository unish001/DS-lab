#include <stdio.h>

// Recursive function to compute Fibonacci number
int fibonacci(int n) {
    if (n == 0)
        return 0; // Base case
    else if (n == 1)
        return 1; // Base case
    else
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive step
}

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci sequence up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}
