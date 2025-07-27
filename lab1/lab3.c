#include <stdio.h>

#define MAX 100

/* Remove duplicates from arr[] in-place; return new size */
int unique(int arr[], int n) {
    int i, j, k = 0;
    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < k; j++) {
            if (arr[i] == arr[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            arr[k++] = arr[i];
        }
    }
    return k;
}

/* Read a set (size + elements), enforce uniqueness */
int inputSet(const char *label, int arr[]) {
    int n;
    printf("Enter size of %s: ", label);
    scanf("%d", &n);
    if (n > MAX) n = MAX;  // basic safety cap
    printf("Enter %d elements for %s: ", n, label);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    n = unique(arr, n);
    return n;
}

/* Display a set */
void displaySet(const char *label, int arr[], int n) {
    printf("%s = { ", label);
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf(" }\n");
}

/* Print Cartesian product A × B */
void cartesianProduct(int A[], int nA, int B[], int nB) {
    printf("A × B = { ");
    for (int i = 0; i < nA; i++) {
        for (int j = 0; j < nB; j++) {
            printf("(%d,%d)", A[i], B[j]);
            /* Put comma+space after each pair except the last one */
            if (!(i == nA - 1 && j == nB - 1)) {
                printf(", ");
            }
        }
    }
    printf(" }\n");
}

int main(void) {
    int A[MAX], B[MAX];
    int nA = inputSet("Set A", A);
    int nB = inputSet("Set B", B);

    printf("\nAfter removing duplicates (treating as sets):\n");
    displaySet("A", A, nA);
    displaySet("B", B, nB);

    if (nA == 0 || nB == 0) {
        printf("\nOne of the sets is empty; Cartesian product is an empty set.\n");
        printf("A × B = { }\n");
    } else {
        printf("\n");
        cartesianProduct(A, nA, B, nB);
    }

    return 0;
}
