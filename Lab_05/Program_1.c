// Implementation and Time analysis of Linear Search Algorithm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000 // Size of the array

// Function to perform linear search
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Element found at index i
        }
    }
    return -1; // Element not found
}

// function to read an array from file
void readArrayFromFile(int arr[], int n, char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
}

// Main function
int main() {
    int arr[N];
    char filename[] = "D:/DAA/Arrays/best_case_100000.txt"; // File containing the array elements
    readArrayFromFile(arr, N, filename);

    int x; // Element to search for
    printf("Enter the element to search for: ");
    scanf("%d", &x);

    // Best Case: Element at the first position
    clock_t start_best = clock();
    int result_best = linearSearch(arr, N, arr[0]);
    clock_t end_best = clock();
    double time_best = ((double)(end_best - start_best)) / CLOCKS_PER_SEC;

    // Average Case: Element at the middle position
    clock_t start_avg = clock();
    int result_avg = linearSearch(arr, N, arr[N/2]);
    clock_t end_avg = clock();
    double time_avg = ((double)(end_avg - start_avg)) / CLOCKS_PER_SEC;

    // Worst Case: Element not present
    clock_t start_worst = clock();
    int result_worst = linearSearch(arr, N, -1); // Assuming -1 is not in the array
    clock_t end_worst = clock();
    double time_worst = ((double)(end_worst - start_worst)) / CLOCKS_PER_SEC;

    // User Case: Element entered by user
    clock_t start = clock(); // Start time measurement
    int result = linearSearch(arr, N, x);
    clock_t end = clock(); // End time measurement

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate time taken
    printf("Time taken for linear search (user input): %f seconds\n", time_taken);

    printf("\n--- Time Analysis ---\n");
    printf("Best Case (element at first position): %f seconds\n", time_best);
    printf("Average Case (element at middle position): %f seconds\n", time_avg);
    printf("Worst Case (element not present): %f seconds\n", time_worst);

    return 0;
}