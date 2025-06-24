// Implement and Analyse time complexity of Selection sort (file input & timing)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int readArrayFromFile(const char *filename, int arr[], int n) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Cannot open file %s\n", filename);
        return 0;
    }
    for (int i = 0; i < n; i++)
        fscanf(f, "%d", &arr[i]);
    fclose(f);
    return 1;
}

int main() {
    int arr[N];
    clock_t start, end;
    double time_taken;

    // Best Case
    if (readArrayFromFile("D:/DAA/Arrays/best_case_100.txt", arr, N)) {
        start = clock();
        selectionSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Best Case Time: %f ms\n", time_taken);
        // printArray(arr, N); // Uncomment to see sorted array
    }

    // Average Case
    if (readArrayFromFile("D:/DAA/Arrays/average_case_100.txt", arr, N)) {
        start = clock();
        selectionSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Average Case Time: %f ms\n", time_taken);
        // printArray(arr, N);
    }

    // Worst Case
    if (readArrayFromFile("D:/DAA/Arrays/worst_case_100.txt", arr, N)) {
        start = clock();
        selectionSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Worst Case Time: %f ms\n", time_taken);
        // printArray(arr, N);
    }

    return 0;
}
// Make sure best_case_100000.txt, average_case_100000.txt, and worst_case_100000.txt exist with 100000 numbers each.