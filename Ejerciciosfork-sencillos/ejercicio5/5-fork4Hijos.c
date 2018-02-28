/* Este programa no crea "s�lo" 4 hijos.
 * Modif�calo para que cree s�lo 4 hijos 
Jos� Manuel P�rez Lobato

Realiza un programa que cree 3 hijos y cada uno de ellos 2 "nietos" y escriban sus identificadores en pantalla*/

#include <stdio.h>
#include <stdlib.h>

int fhijo(int i){
    printf ("Hijo %d, pid =%d, ppid%d\n",i, getpid(),getppid());
     /*Puedes probar a comentar/descomentar el exit para ver la diferencia*/
//    exit (0); 
}

main (){
int i,pid;

for (i=1; i<4; i++){
  pid=fork();
  if (pid==0){ //Hijo
    fhijo(i);
  }
  else
    printf ("El padre ha creado %d hijos \n",i);
} // fin for

} // fin main

