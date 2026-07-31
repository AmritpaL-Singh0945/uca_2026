#include <stdio.h>

int getByte(int x, int n) {
  return (x >> (n << 3)) & 0xFF;
}

int main() {
  printf("getByte(0x12345678, 1) = 0x%X\n", getByte(0x12345678, 1));
  return 0;
}