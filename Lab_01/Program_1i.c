// find factorial of a number using iteration
#include <stdio.h>
int main() {
    int n, i;
    long factorial = 1; // Use long to handle larger values

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }

    for (i = 1; i <= n; ++i) {
        factorial *= i; // Calculate factorial iteratively
    }

    printf("Factorial of %d = %ld\n", n, factorial);
    return 0;
}