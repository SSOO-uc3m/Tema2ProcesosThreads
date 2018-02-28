/*
 * Programa que recibe un n�mero como par�metro y muestra en pantalla 4 veces
 * un mensaje con el n�mero recibido
 * Para que funcione en convinaci�n con los programas padre o padre2 el ejecutable debe llamarse hijo:
 * 	gcc -o hijo hijo.c
*/
//Jos� Manuel P�rez Lobato
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

main(char argc,char *argv[])
{
 int pid;
 int cont=0;

 while (cont<=4)
{  
   pid=getpid();
   printf("Soy hijo %s con Pid: %d  \n",argv[1],pid);
   sleep(2);
   cont++;
 }
} 
