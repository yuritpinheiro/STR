#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sched.h>



void morrer(int sig){

	kill(getpid(), SIGKILL);
}

void alarme2(int sig)
{
	setpriority(PRIO_PROCESS, 0, 19);
	int segundos = alarm(1);
	signal(SIGALRM, morrer);
}
int main(){

	cpu_set_t mask;
	CPU_ZERO(&mask);
	
	CPU_SET(7, &mask);
	int segundo;

	segundo = alarm(2);

	signal(SIGALRM, alarme2);

	sched_setaffinity(0, sizeof(mask), &mask);

	while(1){
		printf("2");
	}
}
