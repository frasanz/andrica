#include <gmp.h>

int main (void) {

     mpz_t p;
		 mpz_t p_ant;
		 mpf_t psq;
		 mpf_t p_antsq;
		 mpz_t gap;
		 mpf_t andrica;
		 mpz_t comp1;
		 mpz_t comp2;


     // p+1 is NOT prime !!!
     //mpz_init_set_str(p, "189452997113368438678230", 10);
		 mpz_init_set_str(p,"1425172824437699411", 10);
		 //mpz_init_set_str(p, "1", 10);

		 mpz_init_set_str(comp1,"500", 10);
		 mpz_init_set_str(comp2,"2", 10);



		 //mpz_init_set_str(p, "1", 10);
		 mpz_init(p_ant);
		 mpz_init(gap);

		 mpf_init(psq);
		 mpf_init(p_antsq);
		 mpf_init(andrica);

		 mpf_set_z(psq,p);
		 mpf_sqrt(psq,psq);
     while (1) {
				 mpz_set(p_ant,p);
				 mpf_set(p_antsq,psq);
         mpz_nextprime(p, p);

				 mpf_set_z(psq,p);
				 mpf_sqrt(psq,psq);
				 mpz_sub(gap,p,p_ant);
				 mpf_sub(andrica,psq,p_antsq);
				 //gmp_printf("%Zd %Zd %Zd %.20Ff\n", p_ant, p,gap, andrica);
				 if(mpz_cmp(gap,comp1)>0){
				 	gmp_printf("%Zd %Zd %.20Ff\n",p_ant, gap, andrica);
				 }
			   //if(mpz_cmp(gap,comp2)==0){
				 //	gmp_printf("twin %Zd, %Zd, %.20Ff\n",p_ant, gap, andrica);
				 //}

     }

     return 0;
}
