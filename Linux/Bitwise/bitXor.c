#include <stdio.h>

int bitXor(int x, int y) {
    return (~(~x & ~y)) & (~(x & y));
}

int main(){
  printf("%d \n",bitXor(4,5));
  return 0;
}