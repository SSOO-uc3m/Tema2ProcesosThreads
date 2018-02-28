/* ¿Cuántas veces aparece en pantalla el mensaje "Soy el hijo n" ?
 * Justifica la respuesta
 */
// José Manuel Pérez Lobato
#include <stdio.h>
#include <stdlib.h>

main () {
int i,pid;

for (i=1; i<=2; i++){
  pid = fork();
  if ( pid==0) {
    printf ("Soy el hijo %d\n", i);
    exit(0);
  }
}

}

