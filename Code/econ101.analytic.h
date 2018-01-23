#ifndef ECON101_ANALYTIC_H_
#define ECON101_ANALYTIC_H_

extern apop_model *econ_101_analytic;
#define fget(r, c) apop_data_get(fixed_params, (r), (c))

static void econ101_analytic_est(apop_data * fixed_params, apop_model *est);
static void econ101_analytic_score(apop_data *fixed_params, gsl_vector *gradient, apop_model *m);
void prep(apop_data *d, apop_model *m);

#endif // ECON101_ANALYTIC_H_
