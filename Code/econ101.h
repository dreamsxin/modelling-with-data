#ifndef ECON101_H_
#define ECON101_H_

extern apop_model *econ_101;
static void econ101_estimate(apop_data *choice, apop_model *p);
static long double budget(apop_data *beta, apop_model* m);
static long double econ101_p(apop_data *d, apop_model *m);

#endif // ECON101_H_
