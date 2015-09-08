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

void alarme(int sig)
{
	setpriority(PRIO_PROCESS, 0, 10);
	int segundo = alarm(2);
	signal(SIGALRM, morrer);
}
int main(){

	cpu_set_t mask;
	CPU_ZERO(&mask);
	CPU_SET(7, &mask);
	sched_setaffinity(0, sizeof(mask), &mask);

	int segundos;
	signal(SIGALRM, alarme);
	
	segundos = alarm(1);
	

	while(1){
		printf("1");

	}
}
