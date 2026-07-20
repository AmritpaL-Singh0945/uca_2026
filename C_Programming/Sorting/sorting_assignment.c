#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quickSortWrapper(int arr[], int n) {
    quickSort(arr, 0, n - 1);
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    }
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    }
    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
    }
}

void mergeSortWrapper(int arr[], int n) {
    mergeSort(arr, 0, n - 1);
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void generateRandom(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
}

void generateAscending(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

void generateDescending(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

typedef void (*SortFunction)(int[], int);

double measureExecutionTime(SortFunction sortFunc, int arr[], int n) {
    clock_t start = clock();
    sortFunc(arr, n);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
}

// this part of code is done with the help of chatgpt for the ease of test case checking

int main() {
    srand((unsigned int)time(NULL));
    int sizes[] = {8000, 12000, 16000, 20000, 24000, 28000, 32000, 36000};
    int num_sizes = 8;

    SortFunction sorts[] = {bubbleSort, insertionSort, selectionSort, quickSortWrapper, mergeSortWrapper, heapSort};
    const char* sortNames[] = {"Bubble Sort", "Insertion Sort", "Selection Sort", "Quick Sort", "Merge Sort", "Heap Sort"};
    int num_sorts = 6;

    const char* orderNames[] = {"Random", "Ascending", "Descending"};

    for (int s = 0; s < num_sizes; s++) {
        int n = sizes[s];
        printf("Array Size: %d\n", n);

        int* originalRandom = (int*)malloc(n * sizeof(int));
        int* originalAscending = (int*)malloc(n * sizeof(int));
        int* originalDescending = (int*)malloc(n * sizeof(int));
        int* testArray = (int*)malloc(n * sizeof(int));

        generateRandom(originalRandom, n);
        generateAscending(originalAscending, n);
        generateDescending(originalDescending, n);

        int* originals[] = {originalRandom, originalAscending, originalDescending};

        for (int o = 0; o < 3; o++) {
            printf("  Order: %s\n", orderNames[o]);
            for (int alg = 0; alg < num_sorts; alg++) {
                copyArray(originals[o], testArray, n);
                double time_taken = measureExecutionTime(sorts[alg], testArray, n);
                printf("    %-15s: %.2f ms\n", sortNames[alg], time_taken);
            }
        }

        free(originalRandom);
        free(originalAscending);
        free(originalDescending);
        free(testArray);
        printf("\n");
    }

    return 0;
}
