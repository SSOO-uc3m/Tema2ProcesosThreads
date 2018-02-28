//Este programa escribe los números enteros del 1 al 10 en pantalla de tal forma que los números pares los escribe el padre y los impares el hijo.
//La sincronización necesaria para que aparezcan en el orden correcto se hace mediante señales.
//Se ha utilizado signal en lugar de sigaction
//Hay que tener en cuenta que el envío de señales no es un buen mecanismo de sincronización y solo se utiliza como ejemplo hasta que se vean métodos mejores

#include <stdio.h>
#include <signal.h>
int n=2;
int m=1;
void capturaSenal1 (int s){ //padre pares
	  printf ("Padre %d\n",n);
	  n=n+2; 
}
void capturaSenal2 (int s){ //hijo impares
	  printf ("Hijo %d\n",m);
	  m=m+2; 
}
main (){
int i,pid;
        signal (SIGUSR1, capturaSenal1);
	signal (SIGUSR2, capturaSenal2);
	pid=fork();
	if (pid !=0)
		sleep(1);	
	while ( m<=10 && n<=10) {	
		if (pid==0){ //hijo 
		   pause();
	           kill(getppid(),SIGUSR1);
		}
	        else { //padre
			kill(pid,SIGUSR2); 
		        pause();
		     }
        }
// return(1);
}
