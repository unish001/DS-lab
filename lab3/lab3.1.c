#include <stdio.h>
#include <string.h>

void combine(char *input, char *output, int start, int end, int index, int r) {
    if (index == r) {
        output[r] = '\0';
        printf("%s\n", output);
        return;
    }

    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
        output[index] = input[i];
        combine(input, output, i + 1, end, index + 1, r);
    }
}

int main() {
    char input[100];
    int r;

    printf("Enter string: ");
    scanf("%s", input);

    printf("Enter number of characters in each combination (r): ");
    scanf("%d", &r);

    int n = strlen(input);
    char output[r + 1]; // one extra for '\0'

    printf("Combinations:\n");
    combine(input, output, 0, n - 1, 0, r);

    return 0;
}
