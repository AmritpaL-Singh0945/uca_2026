#include <stdio.h>

int bang(int x) {
  return ((x | (~x + 1)) >> 31) + 1;
}

int main() {
  printf("bang(3) = %d\n", bang(3));
  printf("bang(0) = %d\n", bang(0));
  printf("bang(-5) = %d\n", bang(-5));

  
  return 0;
}