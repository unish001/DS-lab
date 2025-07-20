#include <stdio.h>

#define N 8  // Size of universal set (max 8 for simplicity here)

void printSet(unsigned char set) {
    printf("{ ");
    for (int i = 0; i < N; i++) {
        if (set & (1 << i))
            printf("%d ", i);
    }
    printf("}\n");
}

int main() {
    unsigned char A, B;
    printf("Assuming universal set = {0,1,2,...,%d}\n\n", N - 1);

    printf("Enter set A as an integer (bit representation): ");
    // e.g. enter 13 (binary 00001101 means elements 0,2,3)
    scanf("%hhu", &A);

    printf("Enter set B as an integer (bit representation): ");
    scanf("%hhu", &B);

    printf("\nSet A = ");
    printSet(A);

    printf("Set B = ");
    printSet(B);

    unsigned char unionSet = A | B;
    unsigned char intersectionSet = A & B;

    printf("\nUnion (A ∪ B) = ");
    printSet(unionSet);

    printf("Intersection (A ∩ B) = ");
    printSet(intersectionSet);

    return 0;
}
