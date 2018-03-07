#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void tratar_alarma(int s) {
	printf("Activada \n");
}

int main() {

	struct sigaction act;
	
	// establece el manejador para SIGALRM 
	act.sa_handler = tratar_alarma;
	act.sa_flags = 0; // ninguna accion especifica 
	sigaction(SIGALRM, &act, NULL);

	act.sa_handler = SIG_IGN; // ignora SIGINT 
	sigaction(SIGINT, &act, NULL);
	
	//signal(SIGALRM,tratar_alarma);
	for(;;){ // recibe SIGALRM cada 10 segundos */
		alarm(10);
		pause();
	}
}
