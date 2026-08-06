#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int size;
    int capacity;
    int isMinHeap;
} Heap;

Heap* createHeap(int capacity, int isMinHeap) {
    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->capacity = capacity;
    h->size = 0;
    h->isMinHeap = isMinHeap;
    h->array = (int*)malloc(capacity * sizeof(int));
    return h;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int compare(Heap *h, int a, int b) {
    if (h->isMinHeap) {
        return a < b;
    }
    return a > b;
}

void heapifyUp(Heap *h, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (compare(h, h->array[index], h->array[parent])) {
            swap(&h->array[index], &h->array[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(Heap *h, int index) {
    int extreme = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < h->size && compare(h, h->array[left], h->array[extreme])) {
        extreme = left;
    }
    if (right < h->size && compare(h, h->array[right], h->array[extreme])) {
        extreme = right;
    }
    if (extreme != index) {
        swap(&h->array[index], &h->array[extreme]);
        heapifyDown(h, extreme);
    }
}

void insertHeap(Heap *h, int val) {
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->array = (int*)realloc(h->array, h->capacity * sizeof(int));
    }
    h->array[h->size] = val;
    heapifyUp(h, h->size);
    h->size++;
}

int extractTop(Heap *h) {
    if (h->size == 0) return 0;
    int top = h->array[0];
    h->array[0] = h->array[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return top;
}

int peekTop(Heap *h) {
    return h->array[0];
}

typedef struct {
    Heap *maxHeap;
    Heap *minHeap;
} MedianFinder;

MedianFinder* createMedianFinder() {
    MedianFinder *mf = (MedianFinder*)malloc(sizeof(MedianFinder));
    mf->maxHeap = createHeap(100, 0); 
    mf->minHeap = createHeap(100, 1);
    return mf;
}

void insert(MedianFinder *mf, int num) {
    if (mf->maxHeap->size == 0 || num <= peekTop(mf->maxHeap)) {
        insertHeap(mf->maxHeap, num);
    } else {
        insertHeap(mf->minHeap, num);
    }

    if (mf->maxHeap->size > mf->minHeap->size + 1) {
        insertHeap(mf->minHeap, extractTop(mf->maxHeap));
    } else if (mf->minHeap->size > mf->maxHeap->size) {
        insertHeap(mf->maxHeap, extractTop(mf->minHeap));
    }
}

float getMedian(MedianFinder *mf) {
    if (mf->maxHeap->size == 0) {
        return 0.0;
    }
    
    if (mf->maxHeap->size > mf->minHeap->size) {
        return (float)peekTop(mf->maxHeap);
    } 
    else {
        return ((float)peekTop(mf->maxHeap) + (float)peekTop(mf->minHeap)) / 2.0;
    }
}

int main() {
    MedianFinder* mf = createMedianFinder();

    int stream[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    int n = sizeof(stream) / sizeof(stream[0]);

    printf("Stream Inputs -> Current Median\n");
    printf("-------------------------------\n");

    for (int i = 0; i < n; i++) {
        insert(mf, stream[i]);
        printf("Inserted: %-2d  -> Median: %.1f\n", stream[i], getMedian(mf));
    }

    return 0;
}