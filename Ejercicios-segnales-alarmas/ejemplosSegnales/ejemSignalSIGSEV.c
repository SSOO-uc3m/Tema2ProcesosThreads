#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*Programa que provoca que se eleve la seneal SIGSEGV
escribiendo en la posicion 0 de memoria la captura. */

void capturar_senyal(int senyal){
    printf("Error por ocupacion indebida de memoria\n");
    signal(SIGSEGV,SIG_DFL);
    exit(-1);
}

int main(void){
    int *p;
    signal(SIGSEGV,capturar_senyal);
    printf ("Ya he colocado el manejador\n");
    p=0;
    printf ("Voy a poner un 5 en la variable\n");
    *p=5; 
    exit(0);
}
