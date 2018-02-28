/* Este programa crea 3 hijos y cada uno de ellos ejecuta el fichero hijo con el
 * parámetro num que varía entre 1 y 3
 * para la ejecución del código de los hijos se utiliza execlp
*/
//José Manuel Pérez Lobato
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUMHIJOS 3

int main()
{
 int i,pid;
 char num[10];

  for(i=1;i<=NUMHIJOS;i++) {
      sprintf(num,"%d",i);
      pid=fork();
      if(pid==0) // hijo
      //  execlp: usamos parámetros individuales en la llamada (l) utilizando la variable path para buscar el comando (p)
        execlp("ls","ls", "-l",NULL);
   //  también se puede poner
   // execlp("./hijo","hijo",num,NULL);
   //  o
   //  execl("hijo","hijo",num,NULL);
  } 
  for(i=1;i<=NUMHIJOS;i++) 
    wait (NULL);

  return 0;
 } //cierre del main
