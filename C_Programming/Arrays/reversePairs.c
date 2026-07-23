#include <stdio.h>

void merge(int arr[],int low,int mid,int high){
  int temp[(high-low)+1];
  int left=low; //i 
  int right=mid+1; //j

  int k=0;

  while (left<=mid && right<=high){
    if (arr[left]<=arr[right]){
      temp[k++]=arr[left++];
    }
    else{
      temp[k++]=arr[right++];
    }
  }

  while (left<=mid){
    temp[k++]=arr[left++];
  }
  while (right<=high){
    temp[k++]=arr[right++];
  }

  for (int i=low;i<=high;i++){
    arr[i]=temp[i-low];
  }
}

int countPairs(int arr[],int low,int mid,int high){
  int right=mid+1;
  int cnt=0;
  for (int i=low;i<=mid;i++){
    while (right<=high && arr[i]>2*arr[right]){
      right++;
    }
    cnt+=(right-(mid+1));
  }
  return cnt;

}
int mergesort(int arr[],int low,int high){
  int cnt=0;
  if (low>=high) return cnt;
  int mid=(low+high)/2;
  cnt += mergesort(arr,low,mid);
  cnt += mergesort(arr,mid+1,high);
  cnt += countPairs(arr,low,mid,high);
  merge(arr,low,mid,high);
  return cnt;
}

int main(){

  int arr[]={40,25,19,12,9,6,2};
  printf("The number of pairs are: %d \n",mergesort(arr,0,6));

  return 0;

}