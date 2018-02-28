#include <stdio.h>
/* Ejemplo de uso de las funciones getpid y getppid para indicar que pid puede conocer cada proceso. Un hijo puede conocer el pid de su padre y el de sus hermanos mayores(creados antes que el) pero, al menos no de forma inmediata, no el de sus hermanos menores
  José Manuel  Pérez Lobato
*/
main () {
int x=0,pidh1, pidh2;
  printf ("Hola \n");
  pidh1=fork ();  /* Creamos el primer hijo*/
  if (pidh1 == 0)  {
    printf ("Hijo1; mipid=%d, pidPadre=%d\n",getpid(), getppid() );
  }
  else {
    printf ("Padre; mipid=%d, pidHijo1=%d, pidPadre=%d\n",getpid(), pidh1, getppid());
    pidh2=fork ();
    if (pidh2 == 0)  {
      printf ("Hijo2; mipid=%d, pidPadre=%d, pid hermano=%d\n",getpid(), getppid(), pidh1 );
    }
    else {
      printf ("Padre; mipid=%d, pidHijo2=%d, pidPadre=%d\n",getpid(), pidh2, getppid());
    }  
  }  
  printf ("Adios\n");
}
