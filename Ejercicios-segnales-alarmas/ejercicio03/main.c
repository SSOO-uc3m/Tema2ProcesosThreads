#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int i;

void par (int s){
	  printf ("%d es un número par \n",i);
}
void impar (int s){
     printf ("%d es un número impar \n",i);}

int main (){
    
    struct sigaction sa;
	sa.sa_handler= par;
	sa.sa_flags=0;
	sigemptyset (&(sa.sa_mask));
	sigaction (SIGUSR1, &sa, NULL);
	
	signal (SIGUSR2, impar);
	
	for  (i=0; i<20; i++){
		sleep(1);
	    if(i%2) kill (getpid(),SIGUSR2);
	    else kill (getpid(), SIGUSR1);

        }
    exit(0);
    
}
