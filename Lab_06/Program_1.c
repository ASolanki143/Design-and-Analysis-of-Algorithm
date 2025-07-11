#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int k = low;
    int l = high + 1;

    k++;
    while(k < high && arr[k] <= pivot){
        k++;
    }
    
    l--;
    while(l > low && arr[l] > pivot) {
        l--;
    }
    
    while (k < l){
        swap(&arr[k], &arr[l]);
        
        k++;
        while (k < high && arr[k] <= pivot){
            k++;
        }

        l--;
        while (l > low && arr[l] > pivot){
            l--;
        }
        
    }
    swap(&arr[low], &arr[l]);
    return l;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int readArrayFromFile(const char *filename, int arr[], int n) {
    FILE *f = fopen(filename, "r");
    // printf("Reading array from file: %s\n", filename);
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

    printf("Quick Sort Performance Analysis\n");

    // Best Case
    if (readArrayFromFile("D:/DAA/Arrays/best_case_10000.txt", arr, N)) {
        printf("Best Case Performance:\n");
        start = clock();
        quickSort(arr, 0, N - 1);
        end = clock();
        printf("%d , %d \n",arr[0],arr[N-1]);
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Best Case Time: %f ms\n", time_taken);
        // printArray(arr, N); // Uncomment to see sorted array
    }

    // Average Case
    if (readArrayFromFile("D:/DAA/Arrays/average_case_10000.txt", arr, N)) {
        start = clock();
        quickSort(arr, 0, N - 1);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Average Case Time: %f ms\n", time_taken);
        // printArray(arr, N);
    }

    // Worst Case
    if (readArrayFromFile("D:/DAA/Arrays/worst_case_10000.txt", arr, N)) {
        start = clock();
        quickSort(arr, 0, N - 1);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Worst Case Time: %f ms\n", time_taken);
        // printArray(arr, N);
    }

    return 0;
}
// Make sure best_case.txt, average_case.txt, and worst_case.txt exist with 100000 numbers each.