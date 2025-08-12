#include <stdio.h>

// Function to implement Euclidean Algorithm (iterative version)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to implement Extended Euclidean Algorithm
int extended_gcd(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    
    int x1, y1;
    int gcd = extended_gcd(b % a, a, &x1, &y1);
    
    *x = y1 - (b / a) * x1;
    *y = x1;
    
    return gcd;
}

int main() {
    int a, b, x, y;
    
    printf("Enter two positive integers: ");
    scanf("%d %d", &a, &b);
    
    // Euclidean Algorithm
    int g = gcd(a, b);
    printf("\nEuclidean Algorithm:\n");
    printf("GCD of %d and %d is %d\n", a, b, g);
    
    // Extended Euclidean Algorithm
    g = extended_gcd(a, b, &x, &y);
    printf("\nExtended Euclidean Algorithm:\n");
    printf("GCD of %d and %d is %d\n", a, b, g);
    printf("Coefficients (x, y) are: %d and %d\n", x, y);
    printf("Verification: %d*%d + %d*%d = %d\n", a, x, b, y, a*x + b*y);
    
    return 0;
}