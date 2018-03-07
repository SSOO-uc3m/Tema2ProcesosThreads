#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* Captura la señal SIGUSR2" y lanza la segnal SIGUSR2 a si mismo*/
void capturaSenalSigusr1 (int s){
	  printf ("Ha llegado la señal SIGUSR1: %d\n",s);
	  kill (getpid(), SIGUSR2);
}

/*Captura la señal SIGUSR2*/
void capturaSenalSigusr2 (int s){
	  printf ("Ha llegado la señal SIGUSR2: %d\n",s);
}

int main (){
    int i;
    struct sigaction sa;

	sa.sa_handler= capturaSenalSigusr1;
	sa.sa_flags=0;
	sigemptyset (&(sa.sa_mask));
	sigaction (SIGUSR1, &sa, NULL);

	signal (SIGUSR2, capturaSenalSigusr22);

	for  (i=0; i<20; i++){
		sleep(1);
		printf ("%d\n",i);
	    if(i%2) kill (getpid(),SIGUSR1);
        }
        
    exit(0);
}
