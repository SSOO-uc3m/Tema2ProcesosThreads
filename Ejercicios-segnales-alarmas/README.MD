**Ejercicio 1.** Implementar un programa en C en el que un proceso padre crea un proceso hijo. El padre, transcurridos 15 segundos de la creación del hijo, debe enviar la señal de SIGUSR1 al proceso hijo, y a continuación terminar su ejecución. 
El proceso hijo, cuando reciba la señal, debe mostrar el siguiente mensaje por pantalla: “SEÑAL RECIBIDA” y a continuación terminar su ejecución.

**Ejercicio 2.** Implementar un programa que espere 3 segundos a que el usuario pulse una tecla. En caso de pasar los 3 segundos sin pulsar nada, el programa termina sin seguir esperando.

**Ejercicio 3.** Implementar un programa que capture la señal SIGUSR1 y la señal SIGUSR2. Se debe hacer un tratamiento diferente para cada señal.

**Ejercicio 4.** Implementar un programa que capture la señal SIGSEGV. Para que salte se debe escribir en la posición 0 de memoria.

**Ejercicio 5.** Implementar un programa en el que el proceso padre crea un hijo. Se debe cumplir lo siguiente:
El padre debe capturar la señal SIGUSR1 y la señal SIGCHLD. Se debe hacer un tratamiento diferente para cada señal.
El hijo se duerme 2 segundos, envía la señal SIGUSR1 al padre, y se duerme 3 segundos antes de terminar.

**Ejercicio 6.** Indicar la jerarquía de procesos creados por este programa al invocarlo de la siguiente manera: 

```
/* Indicar la jerarquía de procesos creados por este programa 
 * al invocarlo con programa 4 5 */
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int seguir =1;

void terminar (int s) {
  seguir =0;
  printf ("%d: alarma\n",getpid());
}
main (int argc, char *argv[]) {
  int i, numparams, pid, v=33;
  struct sigaction act;

  act.sa_handler = terminar;
  sigemptyset(&act.sa_mask);   
  act.sa_flags = 0;
  sigaction(SIGINT, &act, NULL);
  alarm (5);
  i=0;
  numparams=atoi(argv[1]);
  while ( (i< numparams) && seguir){
     if (( pid=fork()) ==0) {
       v++;
       if ( i%2==0 ){
         printf ("Fin en exit Pid %d, v=%d\n",getpid(),v);
         exit (0);
       }
     }
     sleep(2);
     i=i+1;
  }
  printf ("Fin Pid %d, v=%d\n",getpid(),v);
}

```

**Ejercicio 7.** Implementar un programa que escriba los números enteros del 1 al 10 en pantalla de tal forma que los números pares los escribe el padre y los impares el hijo. La sincronización necesaria para que aparezcan en el orden correcto se hace mediante señales. 

**Ejercicio 8.** Escriba un programa que genere un proceso hijo, el cual espera hasta que reciba una señal una señal de SIGINT, tras lo cual se muere, el proceso padre debe esperar a que muera el proceso hijo anterior y crear otro hijo.
todo este proceso se genera en un bucle infinito

**Ejercicio 9.** Escriba una función en C sobre UNIX que permita ejecutar un mandato desde un programa. En caso de que no pueda ejecutarse el mandato, debe dar un mensaje de aviso y retornar al programa sin fallo. Posible declaración:

`int sistema (char *nombre, char *argv)`

La ejecución del mandato se hará mediante un proceso hijo. Durante la ejecución de este proceso hijo, el proceso padre no deberá ser interrumpido por las señales generables desde teclado. El proceso hijo deberá mantener el tratamiento de señales original del padre.


**Ejercicio 10.**

En un sistema UNIX, supóngase que se tiene un proceso que crea un proceso hijo y queda esperando a que éste finalice. Sin embargo, por requisitos del sistema, no puede estar esperando más de 10 segundos. Una vez pasado este tiempo, deberá abortar al proceso hijo, Escriba el código en C del proceso padre.







