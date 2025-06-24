// Implementation and Time analysis of binary Search Algorithm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000 // Size of the array
// Function to perform binary search
int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid; // Element found at index mid
        }
        if (arr[mid] < x) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Element not found
}
// Function to read an array from file
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
    int result_best = binarySearch(arr, N, arr[0]);
    clock_t end_best = clock();
    double time_best = ((double)(end_best - start_best)) / CLOCKS_PER_SEC;

    // Average Case: Element at the middle position
    clock_t start_avg = clock();
    int result_avg = binarySearch(arr, N, arr[N/2]);
    clock_t end_avg = clock();
    double time_avg = ((double)(end_avg - start_avg)) / CLOCKS_PER_SEC;

    // Worst Case: Element not present
    clock_t start_worst = clock();
    int result_worst = binarySearch(arr, N, -1); // Assuming -1 is not in the array
    clock_t end_worst = clock();
    double time_worst = ((double)(end_worst - start_worst)) / CLOCKS_PER_SEC;

    // User Case: Element entered by user
    clock_t start_user = clock(); // Start time measurement
    int result_user = binarySearch(arr, N, x);
    clock_t end_user = clock();
    double time_user = ((double)(end_user - start_user)) / CLOCKS_PER_SEC;

    // Output results
    printf("Best Case: Element found at index %d in %.6f seconds\n", result_best, time_best);
    printf("Average Case: Element found at index %d in %.6f seconds\n", result_avg, time_avg);
    printf("Worst Case: Element found at index %d in %.6f seconds\n", result_worst, time_worst);
    printf("User Case: Element found at index %d in %.6f seconds\n", result_user, time_user);

    return 0;
}