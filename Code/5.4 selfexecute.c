//gcc "5.4 selfexecute.c" -std=gnu99 -lapophenia
//./a.out
//./plot_me

#include <apop.h>
#include <sys/stat.h> //chmod

// a script can be made executable by itself.
// The first line of the script must begin with the special marker #!

int main(){
  char filename[] = "plot_me";
  FILE *f = fopen(filename, "w");
  fprintf(f, "#!/usr/bin/gnuplot -persist\n plot sin(x)");
  fclose(f);
  chmod(filename, 0755);
}
