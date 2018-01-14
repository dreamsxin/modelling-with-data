#include <stdlib.h>
#include <stdio.h>

// a.exe dir
int main(int argc, char **argv){
  int ct=0;
  printf("Printing args...\n");
  for(ct=0; ct<argc; ct++){
    printf("%d = %s\n", ct, argv[ct]);
  }
  printf("...\n");
	
  if(argc==1){ // first arg is program name
    printf("Give me a command to run.\n");  
    return(1);
  }
  int return_value = system(argv[1]);
  printf("The program returned %i.\n", return_value);
  return(0);
}