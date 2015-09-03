#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char ** argv){
	pid_t pid;
	int tempo = 0;

	while (tempo < 35) {
		printf("--------\nEu sou o pai. Meu pid é: %i.\nMeu pai é: %i e agora é: %i.\n", getpid(), getppid(), tempo);
		sleep(1);
		tempo++;

		if (tempo == 10) { // Filho 1
			pid = fork();
			if (pid == 0){
				while (tempo < 40) {
					printf("--------\nEu sou o filho 1. Meu pid é: %i.\nMeu pai é: %i e agora é: %i.\n", getpid(), getppid(), tempo);
					sleep(1);
					tempo++;
					
					if (tempo == 20) { // Neto 1
						pid = fork();
						if (pid == 0) {
							while (tempo < 50) {
								printf("--------\nEu sou o neto 1. Meu pid é: %i.\nMeu pai é: %i e agora é: %i.\n", getpid(), getppid(), tempo);
								sleep(1);
								tempo++;
							}
							exit(0);
						}
					}
				}
				exit(0);
			}
		}

		if (tempo == 15) { // Filho 2
			pid = fork();
			if (pid == 0) {
				while (tempo < 45) {
					printf("--------\nEu sou o filho 2. Meu pid é: %i.\nMeu pai é: %i e agora é: %i.\n", getpid(), getppid(), tempo);
					sleep(1);
					tempo++;
		
					if (tempo == 25) { // Neto 2
						pid = fork();
						while (tempo < 55) {
							printf("--------\nEu sou o neto 2. Meu pid é: %i.\nMeu pai é: %i e agora é: %i.\n", getpid(), getppid(), tempo);
							sleep(1);
							tempo++;
						}
						exit(0);
					}
				}
				exit(0);
			}
		}
	}

	return 0;
}