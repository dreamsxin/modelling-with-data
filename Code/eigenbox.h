#ifndef EIGENBOX_H_
#define EIGENBOX_H_

#include <apop.h>
#include <gsl/gsl_eigen.h>

void show_projection(gsl_matrix *pc_space, apop_data *data);
apop_data *query_data();

#endif // EIGENBOX_H_
