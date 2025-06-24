// Write a program to calculate the power of any number using recursion
#include <stdio.h>
int power(int x, int y) {
    if (y < 0) {
        return -1; // Return -1 for negative exponent
    }
    if (y == 0) {
        return 1; // Base case: any number raised to the power of 0 is 1
    }
    return x * power(x, y - 1); // Recursive case
}
int main() {
    int base, exponent;
    
    printf("Enter the base: ");
    scanf("%d", &base);
    
    printf("Enter the exponent (non-negative integer): ");
    scanf("%d", &exponent);
    
    if (exponent < 0) {
        printf("Exponent should be a non-negative integer.\n");
        return 1;
    }
    
    int result = power(base, exponent);
    printf("%d raised to the power of %d = %d\n", base, exponent, result);
    
    return 0;
}