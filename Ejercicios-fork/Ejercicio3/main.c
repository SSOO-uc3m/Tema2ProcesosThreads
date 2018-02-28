#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main (){
int i,pid;
 
 for (i=0; i<=4; i++){
    pid=fork ();
    if ( pid==0){
       printf ("Hijo %d ( pid=%d)\n",i,getpid());
       exit (0); //return(0);
    }
    else; 
	  // El padre no tiene nada mas que hacer
  }
  
  sleep(10);

    // Para ver los procesos zombies ps -el | grep 'Z'
    

    // El padre finaliza sin esperar a los hijos que se quedan sin padre (zombies)
    return 0;

    /* Si el padre muere teniendo zombies en la tabla de procesos, 
    estos son heredados por init, el cual ejecuta periódicamente la llamada wait()
    para eliminar zombies que le tengan como padre.*/
}

