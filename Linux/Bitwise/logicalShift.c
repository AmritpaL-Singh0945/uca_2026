#include <stdio.h>

int logicalShift(int x, int n) {
  return (x >> n) & ~(((1 << 31) >> n) << 1);
}

int main() {
  printf("logicalShift(0x87654321, 4) = 0x%08X\n", logicalShift(0x87654321, 4));
  printf("logicalShift(0xFFFFFFFF, 31) = 0x%08X\n", logicalShift(0xFFFFFFFF, 31));
  printf("logicalShift(0x87654321, 0) = 0x%08X\n", logicalShift(0x87654321, 0));
  
  return 0;
}
