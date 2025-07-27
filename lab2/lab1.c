#include <stdio.h>

// Recursive function to calculate 2^n
int powerOfTwo(int n) {
    if (n == 0)
        return 1; // Base case
    else
        return 2 * powerOfTwo(n - 1); // Recursive step
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Sequence of 2^n from 0 to %d:\n", n);
    for (int i = 0; i <= n; i++) {
        printf("2^%d = %d\n", i, powerOfTwo(i));
    }

    return 0;
}
