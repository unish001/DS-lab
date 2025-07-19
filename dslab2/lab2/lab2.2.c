#include <stdio.h>
#include <string.h>

void permuteWithRepetition(char *str, char *result, int depth, int length, int maxLen) {
    if (depth == maxLen) {
        result[depth] = '\0';
        printf("%s\n", result);
        return;
    }

    for (int i = 0; i < length; i++) {
        result[depth] = str[i];
        permuteWithRepetition(str, result, depth + 1, length, maxLen);
    }
}

int main() {
    char str[100];
    int len;
    printf("Enter a string (characters may repeat): ");
    scanf("%s", str);
    printf("Enter length of permutations: ");
    scanf("%d", &len);

    int n = strlen(str);
    char result[100];
    printf("Permutations with repetition:\n");
    permuteWithRepetition(str, result, 0, n, len);
    return 0;
}
