#include <stdio.h>
#include <malloc.h>

int globe=1;

int factorial(int *i){
  while(*i){ // the value pointed to by i is not zero
    globe *= *i;
	(*i)--;
  }
  return(globe);
}

int main(void){
  int *a = malloc(sizeof(int));
  *a = 10;
  printf("%i factorial ...", *a);
  printf(" is %i. \n", factorial(a));
  printf("*a=%i\n", *a);
  printf("globe=%i\n", globe);
  free(a);
  return(0);
}