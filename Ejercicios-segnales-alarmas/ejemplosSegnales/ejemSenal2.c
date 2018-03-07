#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void capturaSegnalSigusr1 (int s){
	  time_t horaActual = time(NULL);
	  char* sHoraActual = ctime(&horaActual);
	  printf ("Le llega al padre la segnal SIGUSR1: %d\n",s);
          printf ("Tiempo de llegada:%s\n", sHoraActual);
}

void muerteHijo (int s){
	  time_t horaActual = time(NULL);
	  char* sHoraActual = ctime(&horaActual);
	  printf ("Le llega al padre la señal de que ha terminado el hijo: %d\n",s);
          printf ("tiempo:%s\n", sHoraActual);
}

int main (){
	int i;
	struct sigaction sa1,sa2;

  if (fork() == 0){ /* proceso Hijo*/
      printf("\tProceso hijo: duermo 5 segundos\n");
      sleep (5);
      printf("\tProceso hijo: le envio a mi padre la señal SIGUSR1\n");
      kill ( getppid(), SIGUSR1); // envía una señal al proceso padre
      printf("\tProceso hijo: duermo otros 5 segundos\n");
      sleep(5);
      exit(0);
  }
  else { /*proceso padre*/
    sa1.sa_handler=capturaSegnalSigusr1;
    sa1.sa_flags=0;
    sigemptyset(&(sa1.sa_mask));
    sigaction (SIGUSR1, &sa1,NULL);

    sa2.sa_handler=muerteHijo;
    sa2.sa_flags=0;
    sigemptyset(&(sa2.sa_mask));
    sigaction (SIGCHLD, &sa2,NULL);

    printf("proceso padre: Espero a que me lleguen señales\n");
    pause(); // == sleep(999999) 
    pause(); // == sleep(999999)
    printf ("proceso padre SEGNALES RECIBIDAS\n" );
  }
}
