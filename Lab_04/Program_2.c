    // Implement and Analyse time complexity of Heap sort (file input & timing)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

void max_heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        max_heapify(arr, n, largest);
    }
}

void build_max_heap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(arr, n, i);
}

void heapSort(int arr[], int n) {
    build_max_heap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        max_heapify(arr, i, 0);
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
    if (readArrayFromFile("D:/DAA/Arrays/best_case_100000.txt", arr, N)) {
        start = clock();
        heapSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Best Case Time: %f ms\n", time_taken);
        // printArray(arr, N); // Uncomment to see sorted array
    }

    // Average Case
    if (readArrayFromFile("D:/DAA/Arrays/average_case_100000.txt", arr, N)) {
        start = clock();
        heapSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Average Case Time: %f ms\n", time_taken);
        // printArray(arr, N);
    }

    // Worst Case
    if (readArrayFromFile("D:/DAA/Arrays/worst_case_100000.txt", arr, N)) {
        start = clock();
        heapSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Worst Case Time: %f ms\n", time_taken);
        // printArray(arr, N);
    }

    return 0;
}
// Make sure best_case_100.txt, average_case_100.txt, and worst_case_100.txt exist with 100 numbers each.