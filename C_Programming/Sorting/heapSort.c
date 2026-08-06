#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

bool verifySort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void fillRandom(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000;
    }
}

void fillSorted(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

void fillReverseSorted(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

double measureTime(int arr[], int n, void (*fillFunc)(int[], int)) {
    fillFunc(arr, n);
    
    clock_t start = clock();
    heapSort(arr, n);
    clock_t end = clock();
    
    if (!verifySort(arr, n)) {
        printf("Error: Array not sorted correctly!\n");
        exit(1);
    }
    
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main() {
    srand(time(NULL));

    int testArr[] = {12, 11, 13, 5, 6, 7};
    int testSize = sizeof(testArr) / sizeof(testArr[0]);
    
    printf("Original array: ");
    for(int i=0; i<testSize; i++) printf("%d ", testArr[i]);
    printf("\n");
    
    heapSort(testArr, testSize);
    
    printf("Sorted array:   ");
    for(int i=0; i<testSize; i++) printf("%d ", testArr[i]);
    printf("\nValidation:     %s\n\n", verifySort(testArr, testSize) ? "PASSED" : "FAILED");

    int sizes[] = {10000, 50000, 100000, 200000, 500000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("Execution Time Analysis (in seconds):\n");
    printf("------------------------------------------------------------\n");
    printf("%-10s | %-12s | %-12s | %-12s\n", "Size (n)", "Random", "Ascending", "Descending");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];
        int *arr = (int *)malloc(n * sizeof(int));
        
        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        double timeRandom = measureTime(arr, n, fillRandom);
        double timeSorted = measureTime(arr, n, fillSorted);
        double timeReverse = measureTime(arr, n, fillReverseSorted);

        printf("%-10d | %-12.6f | %-12.6f | %-12.6f\n", 
               n, timeRandom, timeSorted, timeReverse);

        free(arr);
    }
    printf("------------------------------------------------------------\n");

    return 0;
}