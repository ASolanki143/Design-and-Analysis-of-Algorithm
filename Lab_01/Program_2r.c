//  Write a program to calculate the sum of numbers from 1 to n using recursion.
#include <stdio.h>
int sum(int n) {
    if (n < 1) {
        return 0; // Base case: sum is 0 for non-positive integers
    }
    return n + sum(n - 1); // Recursive case
}
int main() {
    int n;
    long result;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    result = sum(n);
    
    if (result < 0) {
        printf("Please enter a positive integer greater than 0.\n");
    } else {
        printf("Sum of numbers from 1 to %d = %ld\n", n, result);
    }

    return 0;
}