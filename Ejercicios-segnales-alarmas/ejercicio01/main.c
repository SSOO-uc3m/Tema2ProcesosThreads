#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void capturaSenal (int s){
	  printf ("Señal recibida: %d\n",s);
}

int main (){
    int pid;
    
    // Creamos una máscara de señales a bloquear durante el manejador
    struct sigaction act;
    act.sa_handler=capturaSenal;
    act.sa_flags=0;
    sigemptyset(&(act.sa_mask)); // creamos un conjunto vacio de señales
	
    pid = fork();
    if (pid != 0){
         sleep (15);
         kill (pid, SIGUSR1);
         exit(0);  
    }
    else { //hijo
         
         sigaction (SIGUSR1, &act,NULL); // especificamos la acción a realizar para SIGUSR1
	 // también podriamos usar signal(SIGUSR1, capturaSenal);
         pause(); // Bloquea al proceso hijo hasta que se reciba la señal, sleep(99999)
         exit(0);
    }
    
}
