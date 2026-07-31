#include <stdio.h>

int isPower2(int x) {
  return !(x & (x + ~0)) & !(x >> 31) & !!x;
}

int main() {
  printf("isPower2(5) = %d\n", isPower2(5));
  printf("isPower2(8) = %d\n", isPower2(8));
  printf("isPower2(0) = %d\n", isPower2(0));
  
  return 0;
}