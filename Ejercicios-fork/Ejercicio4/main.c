#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
const int NUM_HIJOS = 5;
const int NUM_NIETOS = 3;

int main (){
int i,j,pid;
  for (i=1; i<=NUM_HIJOS; i++){
    pid=fork ();  //Creo los hijos
    if ( pid==0){
       printf ("Hijo %d ( pid=%d)\n",i,getpid());
       for (j=1; j<=NUM_NIETOS; j++){
         pid=fork ();  //Creo los nietos 
         if (pid==0){
           printf (" Nieto %d ( pid=%d) del hijo %d (pid=%d)\n", j,getpid(),i,getppid());
	         exit (0);  //fin de los nietos
         }
       }
       for (j=1; j<=NUM_NIETOS; j++)  //Los hijos esperan el fin de sus hijos(los nietos)
         wait (NULL);
         exit (0); //fin de los hijos
    } // fin del if del hijo
  } //fin for de creación de 5 hijos  
  for (i=1; i<=5; i++)  //El padre espera el fin de sus hijos
     wait (NULL);

   return 0;
 }

