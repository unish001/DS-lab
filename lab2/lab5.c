#include <stdio.h>

// Swap function
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Permutations WITHOUT repetition (backtracking)
void permuteWithoutRepetition(int arr[], int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(&arr[start], &arr[i]);
        permuteWithoutRepetition(arr, start + 1, end);
        swap(&arr[start], &arr[i]); // backtrack
    }
}

// Permutations WITH repetition
void permuteWithRepetition(int arr[], int data[], int n, int r, int index) {
    if (index == r) {
        for (int i = 0; i < r; i++)
            printf("%d ", data[i]);
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        data[index] = arr[i];
        permuteWithRepetition(arr, data, n, r, index + 1);
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Permutations WITHOUT repetition:\n");
    permuteWithoutRepetition(arr, 0, n - 1);

    printf("\nPermutations WITH repetition (length = 2):\n");
    int r = 2;
    int data[r];
    permuteWithRepetition(arr, data, n, r, 0);

    return 0;
}
