//gcc "5.10 jitter.c" -std=gnu99 -lapophenia -lgsl -lgslcblas -lsqlite3
//./a.out

#include <apop.h>

void jitter(double *in){
  *in += (gsl_rng_uniform(apop_rng_get_thread()) - 0.5)/10; 
}

int main(){
  apop_db_open("data-tattoo.db");
  gsl_matrix *m = apop_query_to_data("select  \
                    tattoos.'ct tattoos ever had' ct, \
                    tattoos.'year of birth'+1900  yr  \
                    from tattoos                      \
                    where  yr < 1997 and ct+0.0 < 10")->matrix;
  apop_matrix_apply_all(m, jitter);
  printf("set key off; set xlabel 'tattoos';  \n\
          set ylabel 'birth year';            \n\
          plot '-' pointtype 6\n");
  apop_matrix_show(m);
}
