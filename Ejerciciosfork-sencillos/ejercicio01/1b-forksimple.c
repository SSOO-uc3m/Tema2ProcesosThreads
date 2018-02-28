#include <stdio.h>
/*Ejemplo de uso del fork 
José Manuel Pérez Lobato
*/main () {
int x=0,pid;
  printf ("Hola \n"); /*Escrito 1 sóla vez en pantalla*/
  pid=fork (); /*Se crea el hijo */
  if (pid == 0) 
    printf ("Soy el hijo\n"); /* Escrito por el hijo en pantalla*/
  else 
    printf ("Soy el padre\n"); /* Escrito por el padre en pantalla*/
  x++;
  printf ("Adios; x=%d, pid=%d\n",x,pid); /*Escrito 2 veces en pantalla, 1 vez lo escribe el padre y otra el hijo*/
}
