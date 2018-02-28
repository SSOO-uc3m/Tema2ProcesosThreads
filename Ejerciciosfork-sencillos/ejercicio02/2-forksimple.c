/* Indica que aparece en pantalla al ejecutar este programa.
 * Justifica la respuesta
 * */
//José Manuel Pérez Lobato

#include <stdio.h>
main () {
  int a=3,pid;
  
  printf ("Hola\n");
  pid=fork();
  if (pid==0){ //hijo
    a++;
    printf ("hijo: %d\n",a);
  }
  else {
    sleep(1); //Esperamos para que se incremente la variable a.Cuidado hay truco
    printf ("padre: %d\n",a);
  }

}
//Recuerda, cada proceso tiene sus propias variables.
//¿Se ejecutan ambas ramas del if? ¿por qué?
