// factorial(10) is 3628800
#include <stdio.h>
double globe=1;

double factorial(int i){
  while(i){       // while i!=0
    globe *= i--; // multiply globe by i and decrement i
  }
  return(globe);  
}

int main(){
  int a=10;
  printf("%i factorial is %f.\n", a, factorial(a));
  printf("a=%i\n", a);
  printf("globe=%f\n", globe);
  return(0);  
}