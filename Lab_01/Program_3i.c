//  Write a program to count the digits of a given number using iteration.
#include <stdio.h>
int main() {
    int n, count = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    // Count digits iteratively
    do {
        count++;
        n /= 10; // Remove the last digit
    } while (n > 0);

    printf("Number of digits = %d\n", count);
    return 0;
}