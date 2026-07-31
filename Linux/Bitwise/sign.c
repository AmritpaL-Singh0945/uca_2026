#include <stdio.h>

int sign(int x) {
  return (x >> 31) | (!!x);
}

int main() {
  printf("sign(130) = %d\n", sign(130));
  printf("sign(-23) = %d\n", sign(-23));
  printf("sign(0) = %d\n", sign(0));
  
  return 0;
}