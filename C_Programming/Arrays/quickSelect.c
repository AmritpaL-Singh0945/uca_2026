#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int nums[], int idx1, int idx2) {
  int temp = nums[idx2];
  nums[idx2] = nums[idx1];
  nums[idx1] = temp;
}

int partition(int nums[], int start, int end) {
  
  int random = (rand() % (end - start + 1)) + start;

  swap(nums, random, end);
  int pivot = end;

  int i = start - 1;

  for (int j = start; j < end; j++) {

    if (nums[j] <= nums[pivot]) {
      i++;
      swap(nums, i, j);
    }

  }

  swap(nums, ++i, pivot);
  return i;
}

int quickSelect(int nums[], int start, int end, int k) {

  if (start > end) return -1;

  int pivot = partition(nums, start, end);

  if (pivot == k - 1) return pivot;

  if (pivot > k - 1) {
    return quickSelect(nums, start, pivot - 1, k);
  } else {
    return quickSelect(nums, pivot + 1, end, k);
  }

}

int main() {

  srand(time(NULL));

  int k = 100;
  int trials = 100;

  printf("Array Size\tAverage Time (ms)\n");

  for (int n = 8000; n <= 36000; n += 4000) {

    int *nums = (int *)malloc(n * sizeof(int));

    clock_t start = clock();

    for (int t = 0; t < trials; t++) {

      for (int i = 0; i < n; i++) {
        nums[i] = rand();
      }

      quickSelect(nums, 0, n - 1, k);

    }

    clock_t end = clock();

    double timeTaken = ((double)(end - start) * 1000) /
                       (CLOCKS_PER_SEC * trials);

    printf("%d\t\t%.4f\n", n, timeTaken);

    free(nums);

  }

  return 0;

}