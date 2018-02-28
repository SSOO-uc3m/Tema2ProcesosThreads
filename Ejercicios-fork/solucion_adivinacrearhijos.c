/* Indicar la jerarquia de procesos creados por este programa 
 * al invocarlo con programa 4 5 */
//Jose Manuel PErez Lobato
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











/*
 * padre
 * --hijo0
 * --hijo1
 * ----nieto12
 * ----nieto13
 * --hijo2
 * */
