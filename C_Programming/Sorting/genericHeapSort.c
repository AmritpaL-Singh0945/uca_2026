#include <stdio.h>
#include <string.h>

void generic_swap(void *a,void *b,size_t size){
  char temp[size];

  memcpy(temp,a,size);
  memcpy(a,b,size);
  memcpy(b,temp,size);

}

void generic_heapify(void *base,size_t n,size_t i,size_t size,int (*cmp)(const void *a,const void *b)){
  
  size_t largest =i;
  size_t left=2*i+1;
  size_t right=2*i+2;

  char *arr = (char *)base;
  void *largest_ptr=arr+(i*size);
  void *left_ptr=arr+(left*size);
  void *right_ptr=arr+(right*size);


  if (left<n && cmp(left_ptr,largest_ptr)>0){
    largest=left;
    largest_ptr=arr+(largest*size);
  }

  if (right<n && cmp(right_ptr,largest_ptr)>0){
    largest=right;
    largest_ptr=arr+(largest*size);
  }

  if (largest!=i ){
    generic_swap(arr+(i*size),largest_ptr,size);
    generic_heapify(base,n,largest,size,cmp);
  }

}

void heapSort(void *base,size_t n,size_t size,int (*cmp)(const void *a,const void * b)){
  char * arr= (char *)base;
  for (int i=n/2 - 1;i>=0;i--){
    generic_heapify(base,n,i,size,cmp);
  }

  for (int i=n-1;i>0;i--){
    generic_swap(arr,arr+(i*size),size);
    generic_heapify(base,i,0,size,cmp);
  }
}

int compare_ints(const void* a,const void * b){
  int int_a=*(const int*)a;
  int int_b=*(const int*)b;

  return int_a-int_b;
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {

  int arr[] = {3, 4, 1, 2, 5};
  size_t size = sizeof(arr) / sizeof(arr[0]);
  size_t n=sizeof(arr[0]);

  heapSort(arr,size,n,compare_ints);

  for (size_t i=0;i<size;i++){
    printf("%d ",arr[i]);
  }

  printf("\n");

  return 0;
}