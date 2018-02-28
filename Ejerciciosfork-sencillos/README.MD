**Ejercicio 1.** Indica que aparece en pantalla al ejecutar este programa. Justifica la respuesta.

```
#include <stdio.h>
main () {
  int a=3,pid;
  
  printf ("Hola\n");
  pid=fork();
  printf ("Adios\n");
}
```

**Ejercicio 2.** Indica que aparece en pantalla al ejecutar este programa. Justifica la respuesta.

```
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
```

Recuerda, cada proceso tiene sus propias variables. ¿Se ejecutan ambas ramas del if? ¿por qué?

**Ejercicio 4 .** ¿Cuántas veces aparece cada palabra escrita?¿En que orden pueden aparecer?

```
#include <stdio.h>
main (){
  printf ("Hola\n");
  fork ();
  printf ("Uno\n");
  fork ();
  printf ("Dos pid=%d\n",getpid());
}
```
**Ejercicio 5 .** Este programa no crea "sólo" 4 hijos. Modifícalo para que cree sólo 4 hijos 

Realiza un programa que cree 3 hijos y cada uno de ellos 2 "nietos" y escriban sus identificadores en pantalla*/

```
#include <stdio.h>
#include <stdlib.h>

int fhijo(int i){
    printf ("Hijo %d, pid =%d, ppid%d\n",i, getpid(),getppid());
     /*Puedes probar a comentar/descomentar el exit para ver la diferencia*/
//    exit (0); 
}

main (){
int i,pid;

for (i=1; i<4; i++){
  pid=fork();
  if (pid==0){ //Hijo
    fhijo(i);
  }
  else
    printf ("El padre ha creado %d hijos \n",i);
} // fin for

} // fin main
```

**Ejercicio 6 .** Realiza un programa que cree 3 hijos y cada uno de ellos 2 "nietos" y escriban sus identificadores en pantalla*/


