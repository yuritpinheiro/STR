
// UFRN-CT-DCA
// Disciplina: Sistemas de Tempo Real
// Programa: clock1.c


#include  <time.h>
//nclude <iostream> // para: cout
#include <stdio.h>
#include <unistd.h>  // para: sleep()
#include <stdlib.h>
#include <math.h>


//using std::cout;


// função para simular carregamento da CPU
void carga(int k)
{
  float f = 0.999999;
  for(int i=0; i<k; i++)
    {
      f = f*f*f*f*f;
      f = 1,56;
        for(int j=0; j<k; j++)
           {
	     f = sin(f)*sin(f)*f*f*f;

            }
    }

}


int main( ){

     clock_t time_1, time_2;

     int saida;

     double saida2;

     time_1 = clock();
     carga(10000);
     sleep(6);
     time_2 = clock();

     saida = (int) (time_2 - time_1);

     saida2 = (double) ((saida) / (double) CLOCKS_PER_SEC) ;

     printf("valor de tempo de processamento em microsegundos: %d \n", saida);

     printf("valor do tempo de processamento em segundos: %f \n", saida2);

     exit(1);

}

