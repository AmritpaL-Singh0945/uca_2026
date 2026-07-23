#include <stdio.h>

int merge(int arr[],int low,int mid,int high){

  int temp[high-low+1];

  int left=low;
  int right=mid+1;
  int k=0;

  int cnt=0;

  while (left<=mid && right<=high){
    if (arr[left]<=arr[right]) temp[k++]=arr[left++];
    else // right is smaller
    {
      cnt+=(mid-left)+1;
      temp[k++]=arr[right++];
    }

  }

  while (left<=mid) temp[k++]=arr[left++];
  while (right<=high) temp[k++]=arr[right++];

  for (int i=low;i<=high;i++){
    arr[i]=temp[i-low];
  }

  return cnt;
}

int mergeSort(int arr[],int low,int high){
  int cnt=0;
  if (low>=high) return cnt;
  int mid=(high+low)/2;

  cnt+= mergeSort(arr,low,mid);
  cnt+= mergeSort(arr,mid+1,high);
  cnt+= merge(arr,low,mid,high);

  return cnt;
}

int numberOfInversions(int arr[],int n){
  
  return mergeSort(arr,0,n-1);

}

int main(){

  int arr[]={5,3,2,4,1};
  int result=numberOfInversions(arr,5);
  printf("%d \n",result);

  return 0;
 
}