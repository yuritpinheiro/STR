#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char ** argv){
	int act;
	pid_t pid;
	while(true){
		printf("Qual o alvo? ");
		scanf("%i", &pid);

		printf("Qual a missão? ");
		scanf("%i", &act);

		switch(act){
			case 1:
				kill(pid, SIGKILL);
				break;

			case 2:
				kill(pid, SIGSTOP);
				break;

			case 3:
				kill(pid, SIGCONT);
			break;
		}
	}
	return 0;
}