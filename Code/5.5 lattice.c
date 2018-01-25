//gcc "5.5 lattice.c" "eigenbox.c" "oldGnuplotFunctions.c" -std=gnu99 -lapophenia -lgsl -lgslcblas -lsqlite3
//./a.out
// Then run 'gnuplot -persist lattice.txt'

// from https://github.com/b-k/apophenia/blob/master/ChangeLog
// August 2014 ** remove apop_plot_lattice, apop_plot_triangle, apop_plot_li...
// We need apop_plot_lattice to run main
// Find the function here -> https://github.com/b-k/apophenia/wiki/gnuplot_snippets

#include <stdlib.h>
#include "oldGnuplotFunctions.h"
#include "eigenbox.h"

int main(){
    FILE *fp = fopen ("lattice.txt", "w");
    if (!fp){
      perror("Unable to open file");
      exit (EXIT_FAILURE);
    }

  apop_plot_lattice(query_data(), fp);
}

