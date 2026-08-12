#include <stdio.h>

int findNumber(int arr[],int size){
  int result=0;

  for (int i=0;i<32;i++){

    int sum=0;

    for (int j=0;j<size;j++){
      if ((arr[j]>>i) & 1) sum++;
    }

    if ((sum%3)==1){
      result |= (1<<i);
    }
  }

  return result;

}

int main(){
  int arr[]={1,2,3,4,1,2,4,1,2,3,4,3,3};

  int size=sizeof(arr)/sizeof(arr[0]);

  int ans=findNumber(arr,size);

  printf("The number appearing 4 times is %d\n",ans);

  return 0;
  
}