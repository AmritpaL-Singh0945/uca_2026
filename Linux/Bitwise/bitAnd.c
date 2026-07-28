#include <stdio.h>

int bitAnd(int x,int y){

  return ~(~x | ~y);

}

int main(){

  int x=5;
  int y=6;

  printf("%d \n",bitAnd(x,y));

  return 0;
}