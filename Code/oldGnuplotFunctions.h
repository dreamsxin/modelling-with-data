#ifndef OLDGNUPLOTFUNCTIONS_H_
#define OLDGNUPLOTFUNCTIONS_H_

#include <apop.h>
static void printone(FILE *f, double width, double height, double margin, int xposn, int yposn, const apop_data *d);
void apop_plot_lattice(const apop_data *d, FILE *f);

#endif // OLDGNUPLOTFUNCTIONS_H_
