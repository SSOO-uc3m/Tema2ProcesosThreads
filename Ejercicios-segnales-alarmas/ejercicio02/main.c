#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* este programa espera 3 seg a que el usuario pulse un número y si no lo hace deja de esperar */


const int TIEMPO=3;
int finTiempo;

void llegoAlarma (int s){
  printf ("Ha llegado la señal de alarma: %d\n",s);
  finTiempo=1;
}

int main (){
    int n=33;

   
    struct sigaction sa;
	sa.sa_handler = llegoAlarma;
	sa.sa_flags=0;
	sigemptyset (&(sa.sa_mask));
	sigaction (SIGALRM, &sa, NULL);
	//signal(SIGALRM,llegoAlarma);
	alarm(TIEMPO);
		printf ("Dar un número (tiene %d segundos) \n",TIEMPO );
		scanf ("%d",&n);
		if (finTiempo)
		  printf ("Se acabo el tiempo el número sera el %d\n",n );
		else 
		printf ("número leído %d\n",n );
		
	exit(0);
}
