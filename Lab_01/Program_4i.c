// Write a program to calculate the power of any number using iteration.
#include <stdio.h>
#include <math.h>
int main() {
    double base;
    int exponent;
    double result = 1.0; // Initialize result to 1.0 for multiplication

    printf("Enter the base: ");
    scanf("%lf", &base);
    
    printf("Enter the exponent (integer): ");
    scanf("%d", &exponent);

    if (exponent < 0) {
        printf("Exponent should be a non-negative integer.\n");
        return 1;
    }

    // Calculate power iteratively
    for (int i = 0; i < exponent; i++) {
        result *= base; // Multiply base for each iteration
    }

    printf("%.2lf raised to the power of %d = %.2lf\n", base, exponent, result);
    
    return 0;
}
