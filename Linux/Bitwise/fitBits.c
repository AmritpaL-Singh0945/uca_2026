#include <stdio.h>

int fitsBits(int x, int n) {
  int shift = 32 + ~n + 1;
  return !(x ^ ((x << shift) >> shift));
}

int main() {

  printf("fitsBits(5, 3)  = %d \n", fitsBits(5, 3));

  printf("fitsBits(-4, 3) = %d \n", fitsBits(-4, 3));


  return 0;
}