// find the factorial of a number using recursion
#include <stdio.h>
long factorial(int n) {
    if (n < 0) {
        return -1; // Factorial is not defined for negative numbers
    }
    if (n == 0 || n == 1) {
        return 1; // Base case: factorial of 0 or 1 is 1
    }
    return n * factorial(n - 1); // Recursive case
}
int main() {
    int n;
    long result;

    printf("Enter a positive integer : ");
    scanf("%d", &n);

    result = factorial(n);
    
    if (result == -1) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d = %ld\n", n, result);
    }

    return 0;
}