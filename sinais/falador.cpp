
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv){
	while(true){
		printf("Eu sou o matador e meu pid é: %i.\n", getpid());
		sleep(1);
	}
	return 0;
}