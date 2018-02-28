#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void capturaSenal1 (int s){
	  printf ("Ha llegado la señal 1: %d\n",s);
	  kill (getpid(), SIGUSR2);
}

void capturaSenal2 (int s){
	  printf ("Ha llegado la señal 2: %d\n",s);
}

int main (){
    int i;
    struct sigaction sa;

	sa.sa_handler= capturaSenal1;
	sa.sa_flags=0;
	sigemptyset (&(sa.sa_mask));
	sigaction (SIGUSR1, &sa, NULL);
	signal (SIGUSR2, capturaSenal2);
	for  (i=0; i<20; i++){
		sleep(1);
		printf ("%d\n",i);
	    if(i%2) kill (getpid(),SIGUSR1);
        }
        
    exit(0);
}
