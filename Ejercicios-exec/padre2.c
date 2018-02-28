/* Programa que crea 3 hijos que ejecutan el fichero hijo con el parámetro 1, 2 o 3.
 * Para la ejecución del código de los hijos se utiliza execvp 
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUMHIJOS 3
main(int argc, char *argv[], char *envp[])
{
 int i,pid;
 char num[10];
 char *params[3];

  params[0]=(char *) malloc (10*sizeof(char));
  strcpy (params[0], "hijo");
  params[1]=(char *) malloc (10*sizeof(char));
  for(i=1;i<=NUMHIJOS;i++) {
      sprintf(params[1],"%d",i);
      params[2]=NULL;
      pid=fork();
      if(pid==0) //crear hijo
        execvp("./hijo",params);
      //También podría ponerse:  execve("./hijo",params,envp);
      sleep(1);
  }   
    
 } //cierre del main
