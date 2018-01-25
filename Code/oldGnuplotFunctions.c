#include "oldGnuplotFunctions.h"

/* This produces a Gnuplot file that will produce an array of 2-D
 plots, one for each pair of columns in the data set. Along the diagonal
 is a plot of the variable against itself---a density plot of the variable.

 \param d  The data set whose (matrix) columns will be compared.
 \param f  The output pipe. E.g., fopen("lattice.gnuplot", "w") or popen("gnuplot --persist", "w")
*/
void apop_plot_lattice(const apop_data *d, FILE *f){
    double  width  = 1.2,//feel free to make these variable inputs.
            height = 1.2;
    double  margin = 0;
    fprintf(f, "set size %g, %g\n"
                "set rmargin 5\n"
                "set lmargin -1\n"
                "set tmargin 2.4\n"
                "set bmargin -2\n"
                "set origin %g, %g       \n"
                "set multiplot   #layout %zu, %zu downwards        \n"
                "unset xtics; unset xlabel; unset ytics; unset ylabel\n"
                "set nokey           \n"
        , width, height, margin,margin, d->matrix->size2, d->matrix->size2);
    for (size_t i = 0; i< d->matrix->size2; i++)
        for (size_t j = 0; j< d->matrix->size2; j++)
            printone(f, width, height, margin, i, j, d);
    fprintf(f, "unset multiplot\n");
}

/* the next function plots a single graph for the \ref apop_plot_lattice  fn */
static void printone(FILE *f, double width, double height, double margin, int xposn, int yposn, const apop_data *d){
    //pull two columns
    size_t count    = d->matrix->size2;
    double nudge    = 0.08;
    gsl_vector  v1  = gsl_matrix_column(d->matrix, xposn).vector;
    gsl_vector  v2  = gsl_matrix_column(d->matrix, yposn).vector;
    gsl_matrix  *m  = gsl_matrix_alloc(d->matrix->size1, 2);
    gsl_matrix_set_col(m, 0, &v1);
    gsl_matrix_set_col(m, 1, &v2);
    double sizex    = (double)(width - margin * (count -1))/count;
    double sizey    = (double)(height - margin * (count -1))/count;
    double offx     = width - (sizex +margin-nudge)* (count - xposn) - nudge*count;
    double offy     = height - (sizey +margin-nudge)* (1 + yposn) - nudge*count;
        fprintf(f, "unset y2tics; unset y2label; unset ytics; unset ylabel\n");
        fprintf(f, "unset x2tics; unset x2label; unset xtics; unset xlabel\n");
    fprintf(f, "set size   %g, %g\n"
               "set origin %g, %g\n"
                ,  sizex, sizey, offx, offy);
    //Gnuplot has no way to just set a label with no plot, so 
    //labels have to be drawn with a long offset from one of the
    //plots we do display.
    if (xposn  == yposn+1)
        fprintf(f, "set label %i '%s' center at graph %g, %g\n",yposn+1, (d->names->colct >yposn)? d->names->col[yposn]: "",  -0.5, 0.5);
    if ((yposn == count-1) && (xposn  == count-2))
        fprintf(f, "set label %zu '%s' center at graph %g, %g\n",count, (d->names->colct >count -1)? d->names->col[count -1]: "",  1.5, 0.5);
    if (xposn != yposn){
        fprintf(f, "plot '-'\n");
        fflush(f);
        apop_matrix_print(m, NULL, f, 'p');
        fprintf(f,"e\n");
        gsl_matrix_free(m);
    }
    if (xposn  == yposn+1)
        fprintf(f, "unset label %i \n",yposn+1);
    if ((yposn == count-1) && (xposn  == count-2))
        fprintf(f, "unset label %zu\n",count);
}

