// Write a program to calculate the sum of numbers from 1 to n using iteration.
#include <stdio.h>
int main() {
    int n, i;
    long sum = 0; // Use long to handle larger sums

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }

    for (i = 1; i <= n; ++i) {
        sum += i; // Calculate sum iteratively
    }

    printf("Sum of numbers from 1 to %d = %ld\n", n, sum);
    return 0;
}