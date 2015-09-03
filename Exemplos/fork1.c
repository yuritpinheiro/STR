// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa: fork1

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{

// declarações de variáveis
  pid_t pid;          // definindo um identificador de processo - inteiro longo
  char *mensagem;     // string que contém a mensagem
  int n;              // contador 
   
  printf("Começando o programa fork1 ... \n");
  pid = fork();   // dividindo o processo em dois
  switch(pid)
    {
    case -1:       // erro na abertura do processo filho
      exit(1);  
    case 0:        // Parte a ser executada pelo processo Filho
      mensagem = "Eu sou o processo Filho...";
      n = 10;      // contador do processo Filho
      break;
    default:       // parte a ser executada pelo processo Pai
      mensagem = "Eu sou o processo Pai ...";
      n = 5;      // contador do processo Pai
      break;
    }

   // execução de ambos os processos
  for(int i=0;i<n;i++) {
    printf("\n Valor de pid %d   ",pid);
    puts(mensagem);
    sleep(1);
    if (pid ==0) {system("ps -auxf | grep fork1 &");     }
  }
  if (pid == 0) {    // execução do processo Filho
     printf("Terminando o programa fork1: Processo Filho ... \n");
  }
  else {    // execução do processo pai
     printf("Terminando o programa fork1: Processo Pai ... \n");
  }
  exit (0);

}
