#include <stdio.h>

// Function to display a set
void displaySet(int set[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", set[i]);
    }
    printf("}\n");
}

// Union of two sets
void unionSet(int set1[], int size1, int set2[], int size2, int result[], int *size3) {
    *size3 = 0;
    for (int i = 0; i < size1; i++)
        result[(*size3)++] = set1[i];
    for (int i = 0; i < size2; i++) {
        int found = 0;
        for (int j = 0; j < size1; j++) {
            if (set2[i] == set1[j]) {
                found = 1;
                break;
            }
        }
        if (!found)
            result[(*size3)++] = set2[i];
    }
}

// Intersection of two sets
void intersectionSet(int set1[], int size1, int set2[], int size2, int result[], int *size3) {
    *size3 = 0;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (set1[i] == set2[j]) {
                result[(*size3)++] = set1[i];
                break;
            }
        }
    }
}

// Difference of two sets (A - B)
void differenceSet(int set1[], int size1, int set2[], int size2, int result[], int *size3) {
    *size3 = 0;
    for (int i = 0; i < size1; i++) {
        int found = 0;
        for (int j = 0; j < size2; j++) {
            if (set1[i] == set2[j]) {
                found = 1;
                break;
            }
        }
        if (!found)
            result[(*size3)++] = set1[i];
    }
}

// Complement of a set with respect to universal set
void complementSet(int universal[], int sizeU, int set[], int sizeS, int result[], int *sizeC) {
    *sizeC = 0;
    for (int i = 0; i < sizeU; i++) {
        int found = 0;
        for (int j = 0; j < sizeS; j++) {
            if (universal[i] == set[j]) {
                found = 1;
                break;
            }
        }
        if (!found)
            result[(*sizeC)++] = universal[i];
    }
}

int main() {
    // Predefined data
    int universal[] = {1, 2, 3, 4, 5, 6};
    int setA[] = {1, 2, 3};
    int setB[] = {2, 3, 4};
    int sizeU = 6, sizeA = 3, sizeB = 3;

    int result[100], sizeR;

    printf("Universal Set U = ");
    displaySet(universal, sizeU);

    printf("Set A = ");
    displaySet(setA, sizeA);

    printf("Set B = ");
    displaySet(setB, sizeB);

    // Union
    unionSet(setA, sizeA, setB, sizeB, result, &sizeR);
    printf("\nUnion (A ∪ B) = ");
    displaySet(result, sizeR);

    // Intersection
    intersectionSet(setA, sizeA, setB, sizeB, result, &sizeR);
    printf("Intersection (A ∩ B) = ");
    displaySet(result, sizeR);

    // Difference
    differenceSet(setA, sizeA, setB, sizeB, result, &sizeR);
    printf("Difference (A - B) = ");
    displaySet(result, sizeR);

    // Complement
    complementSet(universal, sizeU, setA, sizeA, result, &sizeR);
    printf("Complement of A (A') = ");
    displaySet(result, sizeR);

    return 0;
}
