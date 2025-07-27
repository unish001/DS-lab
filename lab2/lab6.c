#include <stdio.h>

void combine(int arr[], int data[], int start, int end, int index, int r) {
    if (index == r) {
        for (int j = 0; j < r; j++)
            printf("%d ", data[j]);
        printf("\n");
        return;
    }

    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
        data[index] = arr[i];
        combine(arr, data, i + 1, end, index + 1, r);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int r = 2; // size of each combination
    int n = sizeof(arr) / sizeof(arr[0]);
    int data[r];

    printf("Combinations of %d elements:\n", r);
    combine(arr, data, 0, n - 1, 0, r);
    return 0;
}
