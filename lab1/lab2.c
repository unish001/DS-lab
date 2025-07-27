#include <stdio.h>

#define SIZE 5  // Number of elements

// Display fuzzy set
void displaySet(float set[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%.1f ", set[i]);
    }
    printf("}\n");
}

// Fuzzy Union
void fuzzyUnion(float A[], float B[], float result[], int size) {
    for (int i = 0; i < size; i++) {
        result[i] = (A[i] > B[i]) ? A[i] : B[i];
    }
}

// Fuzzy Intersection
void fuzzyIntersection(float A[], float B[], float result[], int size) {
    for (int i = 0; i < size; i++) {
        result[i] = (A[i] < B[i]) ? A[i] : B[i];
    }
}

// Fuzzy Complement
void fuzzyComplement(float A[], float result[], int size) {
    for (int i = 0; i < size; i++) {
        result[i] = 1 - A[i];
    }
}

int main() {
    // Fuzzy sets with simple membership values
    float A[SIZE] = {0.1, 0.5, 0.7, 0.3, 1.0};
    float B[SIZE] = {0.4, 0.6, 0.2, 0.9, 0.5};
    float result[SIZE];

    printf("Fuzzy Set A = ");
    displaySet(A, SIZE);

    printf("Fuzzy Set B = ");
    displaySet(B, SIZE);

    // Union
    fuzzyUnion(A, B, result, SIZE);
    printf("\nUnion (A ∪ B) = ");
    displaySet(result, SIZE);

    // Intersection
    fuzzyIntersection(A, B, result, SIZE);
    printf("Intersection (A ∩ B) = ");
    displaySet(result, SIZE);

    // Complement of A
    fuzzyComplement(A, result, SIZE);
    printf("Complement of A (A') = ");
    displaySet(result, SIZE);

    return 0;
}
