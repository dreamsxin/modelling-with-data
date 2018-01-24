//gcc plotmeExtended.c
//./a.out

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void writeGunplotCommandToFile(char *fileName, char* gnuplotCommand){

  // remove the file if it already exists
  if(access(fileName, F_OK) != -1){ // access function defined in unistd.h
    if(remove(fileName) == 0)
      printf("File '%s' deleted.\n", fileName);
    else
      fprintf(stderr, "Error deleting the file '%s'.\n", fileName);
  }

  // now create the file we'll use for plotting
  FILE *f = fopen(fileName, "w");
  if (f == NULL){
    printf("Error opening file!\n");
    exit(1);
  }

  fprintf(f, "%s\n", gnuplotCommand);
  fclose(f);
}

int main(){
  char *fileName = "plotme2.txt";
  char *gnuplotCommand = "plot tan(x)";
  writeGunplotCommandToFile(fileName, gnuplotCommand);
  system("gnuplot -persist plotme2.txt");
}

