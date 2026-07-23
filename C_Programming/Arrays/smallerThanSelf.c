#include <stdlib.h>

void merge(int* nums, int* indices, int* count, int low, int mid, int high) {
    int temp[high - low + 1]; 
    int left = low;
    int right = mid + 1;
    int k = 0;
    int rightCounter = 0;

    while (left <= mid && right <= high) {
        if (nums[indices[left]] <= nums[indices[right]]) {
            count[indices[left]] += rightCounter;
            temp[k++] = indices[left++];
        } else {
            rightCounter++;
            temp[k++] = indices[right++];
        }
    }

    while (left <= mid) {
        count[indices[left]] += rightCounter;
        temp[k++] = indices[left++];
    }

    while (right <= high) {
        temp[k++] = indices[right++];
    }

    for (int i = 0; i < k; i++) {
        indices[low + i] = temp[i];
    }
}

void mergeSort(int* nums, int* indices, int* count, int low, int high) {
    if (low >= high) return;
    int mid = low + (high - low) / 2;

    mergeSort(nums, indices, count, low, mid);
    mergeSort(nums, indices, count, mid + 1, high);
    
    merge(nums, indices, count, low, mid, high);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    if (numsSize == 0) return NULL;

    int* count = (int*)calloc(numsSize, sizeof(int));
    int* indices = (int*)malloc(numsSize * sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        indices[i] = i;
    }

    mergeSort(nums, indices, count, 0, numsSize - 1);

    free(indices);
    return count;
}