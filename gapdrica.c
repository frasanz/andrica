#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include "boinc_api.h"
#include "gui_rpc_client.h"
#include "filesys.h"
#include "diagnostics.h"

#define OUTPUT_FILENAME "output"

int main (void) {
		 boinc_init();
		 mpz_t init;    // The initial number
     mpz_t p;       // To store the prime
		 mpz_t p_ant;   // To store the previous prime
		 mpf_t psq;     // To store the sqrt of the prime
		 mpf_t p_antsq; // To store the sqrt of the previous prime
		 mpz_t gap;     // To store the gap
		 mpf_t andrica; // To store the andrica

		 /* Some numbers to compare */
		 mpz_t comp;
		 mpz_t window;
		 mpz_t upperbound;

		 /* Some aux */
		 mpz_t aux;
		 mpf_t auxf;
		 mpf_t windowf;

		 FILE *fo;
     char output_path[512];
     boinc_resolve_filename(OUTPUT_FILENAME, output_path, sizeof(output_path));


		 /* Initialization */
		 mpz_init_set_str(init,"4000000000000000000",10);
		 mpz_init(p);
		 mpz_set(p, init);

		 /* Show if gap is greather than */
		 mpz_init_set_str(comp,"500", 10);

		 /* Doing up to */
		 mpz_init_set_str(window,"500000000", 10);
		 mpz_init(upperbound);
		 mpz_add(upperbound, window, p);

		 mpz_init(p_ant);
		 mpz_init(gap);

		 mpf_init(psq);
		 mpf_init(p_antsq);
		 mpf_init(andrica);
		 mpf_set_z(psq,p);
		 mpf_sqrt(psq,psq);
		 mpz_init(aux);
		 mpf_init(windowf);
		 mpf_init(auxf);

     while (mpz_cmp(upperbound,p)>0) {
				 mpz_set(p_ant,p);
         mpz_nextprime(p, p);

				 mpz_sub(gap,p,p_ant);
				 if(mpz_cmp(gap,comp)>0){
					/* Gap is greater than comp 
					 * doing andrica */
				  mpf_set_z(p_antsq,p_ant);
					mpf_sqrt(p_antsq,p_antsq);

				  mpf_set_z(psq,p);
				 	mpf_sqrt(psq,psq);

				  mpf_sub(andrica,psq,p_antsq);

					/* Open boinc output file */
					boinc_resolve_filename(OUTPUT_FILENAME, output_path, sizeof(output_path));
					fo = boinc_fopen(output_path, "a+");
					if(!fo) {
						fprintf(stderr,"Couln't find output file, resolved name %s.\n", output_path);
						exit(-1);
					}
				 	gmp_fprintf(fo,"%Zd %Zd %.20Ff\n",p_ant, gap, andrica);
          fclose(fo);

					/* Calculate the percentage */
					mpz_sub(aux,p,init);
					mpf_set_z(auxf, aux);
					mpf_set_z(windowf, window);
					mpf_div(auxf, auxf, windowf);
					gmp_printf("%.3Ff\n",auxf);
					boinc_fraction_done(mpf_get_d(auxf));
				 }
     }
		 gmp_printf("%Zd\n",p);
		 boinc_finish(0);
     return 0;
}
