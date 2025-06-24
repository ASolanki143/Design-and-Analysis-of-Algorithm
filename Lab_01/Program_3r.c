// Write a program to count the digits of a given number using recursion.
#include <stdio.h>

int countDigits(int n){
    if (n == 0) {
        return 0; // Base case: no digits in 0
    }
    return 1 + countDigits(n / 10); // Recursive case: count the last digit and recurse on the rest
}

int main() {
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    int result = countDigits(n);
    printf("Number of digits = %d\n", result);
    
    return 0;
}