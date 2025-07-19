#include <stdio.h>
#include <string.h>

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *str, int l, int r) {
    if (l == r) {
        printf("%s\n", str);
        return;
    }

    for (int i = l; i <= r; i++) {
        swap((str + l), (str + i));
        permute(str, l + 1, r);
        swap((str + l), (str + i)); // backtrack
    }
}

int main() {
    char str[100];
    printf("Enter a string (no repeating characters): ");
    scanf("%s", str);
    int n = strlen(str);
    printf("Permutations without repetition:\n");
    permute(str, 0, n - 1);
    return 0;
}
