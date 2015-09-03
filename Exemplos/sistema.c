// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa: sistema.c



#include <stdlib.h>
#include <stdio.h>

int main ()
{
 printf("Rodando o comando ps com system(): Início \n");
 system ("./sleep &");
 system ("./sleep &");
 system ("ps -auf | grep sleep &");
 printf("Rodando o comando ps com system(): Fim \n");
 exit (0);
}
