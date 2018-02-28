#include <stdio.h>
#include <signal.h>
void tratar_senyal(){
	printf("Hijo muere\n");
	exit(0);
}
main (int argc, char **argv) { 
	int pid, status;
	for (;;){
		printf("Padre: creando hijo\n");
		pid = fork();
		if (pid == 0) {
			printf("Hijo: esperando\n");
			signal (SIGINT, tratar_senyal);
			for(;;)
				sleep(1);
		}else{
			signal (SIGINT, SIG_IGN);
			/*
			Es equivalente a:
			struct sigaction act;
			act.sa_handler = SIG_IGN;
			act.flags = 0;
			sigemptyset(&act.sa_mask);
			sigaction(SIGINT, &act, NULL); 	
			*/
			printf("Padre: esperando al hijo %d\n",pid);
			wait(&status);
		}	
	}
}
