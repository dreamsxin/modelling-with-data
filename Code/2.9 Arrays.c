#include <stdlib.h>
#include <stdio.h>

int main(){
  int i, array_length = 1000;
  int *squares = malloc(array_length*sizeof(int));
  for(i=0; i<array_length; i++)
    squares[i] = i * i;

  // print a few
  for(i=0; i<5; i++)
    printf("%d,", squares[i]); // 0,1,4,9,16,
  printf("\n");
}