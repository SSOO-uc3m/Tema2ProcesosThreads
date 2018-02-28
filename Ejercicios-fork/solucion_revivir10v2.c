/* Esta aplicaci�n crea 10 hijos, cada uno de los cuales debe escribir el n�mero que le corresponda (el hijo 0 escribe el n�mero 0, el hijo 1 el n�mero 1,..) 1 vez por segundo hasta que le llegue la se�al SIGUSR1.
 * Cuando a un hijo le llega la se�al indicada debe finalizar su ejecuci�n mostrando un mensaje del tipo "Hijo de pid PID finaliza la ejecuci�n" donde PID corresponde al pid del proceso.
 * El proceso padre de los hijos debe, despu�s de crear a los 10 hijos, debe eseperar que finalice alguno de ellos, cuando detecte la finalizaci�n de alguno de ellos debe crear otro que realice la misma funci�n que el que muri�. Es decir si finaliza el que escribia el n�mero 3 crear� otro para que escriba el n�mero 3.
*/
//Jose Manuel PErez Lobato
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
int fin=0;
void terminar (int s){
fin =1;
}

void hijo(int i){
int veces,j;
srandom (getpid());
veces=random()%4+3;
for (j=0; j<veces; j++){
  printf ("Hijo %d (pid=%d)\n",i,getpid());
  sleep (1);
}
  printf ("Hijo de pid  %d finaliza la ejecuci�n del hijo %d\n",getpid(),i);
  exit (0);
}

void revivir (int *pid){
int pidm,i;

pidm=wait(NULL);
printf("El padre ha detectado la muerte del hijo %d\n", pidm);
for (i=1; i<4 ;i++)
  if (pidm==pid[i])
    if (( pid[i]=fork())==0)
      hijo(i);
    else{
      printf("El padre ha sustituido al hijo %d\n",i);
      break;
    }
}

main () {
int pid[10],i;
for (i=1; i<4; i++)
  if (( pid[i]=fork()) ==0)
    hijo(i);

 while (1)
  revivir (pid);
}
