#include <stdio.h>

int powerOfTwo(int n) 
{

    if (n == 0)
        return 1;
    return 2 * powerOfTwo(n - 1);
}

int main() 
{
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);
    printf("2^%d = %d\n", n, powerOfTwo(n));
    return 0;
}
