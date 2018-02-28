/*17.Programa que provoca que se eleve la seneal SIGSEGV (escribiendo en la*/
/*posicion 0 de memoria) y capturarla.*/
/*directrices de compilacion*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void capturar_seneal(int segnal){
    printf("Se ha producido un error por intento de ocupacion indebida de memoria\n");
    signal(SIGSEGV,SIG_DFL);
}

main(void){
    int *p;
    signal(SIGSEGV,capturar_seneal);
    printf ("Ya he colocado el manejador\n");
    p=0;
    printf ("Voy a poner un 5 en la variable\n");
    *p=5; 
}


