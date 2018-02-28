/* Este programa ejecuta en un proceso hijo el programa pasado como parámetro 
 * (que no puede tener argumentos).
 * Compilar con 
 *  gcc -o execcomando execcomando.c 
 * Probarlo ejecutándolo con 
 *   execcomando ls
 * o con 
 *   execcomando date
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
 int pid;
     
 pid=fork();
 if(pid==0){ //crear hijo
        printf ("Hijo creado, va a ejecutar el comando %s\n",argv[1]);
	// execvp: pasamos los parámetros en un array de *char (v) utilizando la variable path para buscar el comando (p)
        execvp (argv[1], &argv[1]); 
	printf ("ERROR, aquí sólo se llega si ha fallado el exec\n");
  }   
  wait (NULL);
  printf ("FIN  del padre\n");
  
  return 0;
 } //cierre del main
