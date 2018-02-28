/* En este programa el hijo pide un número y el padre escribe una secuencia creciente
 desde el último número introducido (el número tiene que estar entre 0 y 255) hasta 
 que el padre vuelva a leer otro número.
* Es una forma de ver como se pueden hacer 2 acciones en paralelo y con comunicación
 entre los 2 procesos que las llevan a cabo, uno pidiendo números y otro escribiendo 
 la secuencia que empieza en el número introducido. */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

const short TAM_VALOR_ESTADO = 255; // 8 bits 

/* El hijo pide un número y se lo pasa al padre cuando se muere como valor de estado de 8 bits */
void leerNumero(){
    int numLeido=1;
    printf("Hijo: Introduce un numero: (de 0 a %d) \n",TAM_VALOR_ESTADO);
    scanf("%d", &numLeido);
    exit(numLeido);
}

int main()
{
int pid,estado;
int numescrito=1;
  //El padre crea un hijo para que lea un número mientras el está escribiendo la secuencia
  pid=fork();
  if(pid==0)
      leerNumero(); 
  while(1) {
    printf("Padre: %d\n",numescrito);
    sleep(1);
    numescrito++;
    /*Compruebo si el hijo se ha muerto y por tanto ha leído un número que tengo 
    que utilizar en la nueva secuencia, que leeremos de forma inmediata sin esperar */
    if(waitpid(pid,&estado)) {
      numescrito=WEXITSTATUS(estado);
      // Si el hijo ha muerto creo otro para que lea otro número
      pid=fork();
      if(pid==0)
        leerNumero();
    }
  }
}
