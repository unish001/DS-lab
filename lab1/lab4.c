#include <stdio.h>
#include <math.h>

int main() {
    float num;
    printf("Enter a number: ");
    scanf("%f", &num);

    int floorValue = floor(num);
    int ceilValue = ceil(num);

    printf("Number: %.2f\n", num);
    printf("Floor: %d\n", floorValue);
    printf("Ceiling: %d\n", ceilValue);

    return 0;
}
