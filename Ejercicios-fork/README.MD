**Ejercicio 1.** Dado el siguiente programa, denominado crear\_procesos1:

```
#include <stdio.h>
main (int argc, char **argv) 
{
	int num_proc, i, pid;

	num_proc = atoi (argv[1]);
	for (i=0; i<num_proc; i++) {
		pid = fork();
		if (pid == 0) {
			write (1, "Soy un proceso", 14); }
	}
}

```
Y el programa crear_procesos2:
```
#include <stdio.h>
main (int argc, char **argv) 
{
	int num_proc, i, pid, status;

	num_proc = atoi (argv[1]);
	for (i=0; i<num_proc; i++) {
		pid = fork();
		if (pid == 0) {
			write (1, "Soy un proceso", 14); }
		else 
			while(pid != wait (&status)); //bucle esperando la finalización del hijo creado
	}
}
```

Se pide:

1. Dibujar un esquema que muestre la jerarquía de procesos si el usuario ejecuta los mandatos crear\_procesos1 3 y crear\_procesos2 3 sucesivamente.
2. ¿Pueden quedar procesos zombies?


**Ejercicio 2.** Dado el programa que se muestra a continuación, responda a las cuestiones:

```
#include <stdio.h>
#include <stdlib.h>
main() {
	int pid,i, m=10;
	int tiempoinicial, tiempoactual;
	tiempoinicial = time(NULL);//time devuelve el tiempo actual en segundos
	tiempoactual = time(NULL) - tiempoinicial;
 	printf("%d:Inicio del programa \n",tiempoactual );
	for(i=0; i<3; i++) {
		pid=fork();
    	sleep(1);
    	switch(pid) {
      	case -1: 
				perror("Error en la creación de procesos");
				exit(-1);
       	case 0: 
				m++;
				tiempoactual = time(NULL) - tiempoinicial;
				printf("%d:Hijo %d m=%d\n",tiempoactual, i, m);
				sleep(2);
            	exit(0);
       	default: 
				tiempoactual = time(NULL) - tiempoinicial;
    			printf("%d:Creado el proceso %d\n", tiempoactual, i);
				if( i%2 == 0 ) {
		   			wait(NULL); //wait espera que finalice un hijo cualquiera
					tiempoactual = time(NULL) - tiempoinicial;
printf("%d:Finalizó un proceso, valor de m=%d\n", tiempoactual,m);
    			} //fin if  
    	} //fin switch  
  	} //fin for  
  	wait(NULL);
	tiempoactual = time(NULL) - tiempoinicial;
  	printf("%d:Finalizó un proceso, valor de m=%d",tiempoactual, m);
} //fin main


```

1. Escribir los mensajes que se escriben por pantalla y en qué instante, suponiendo que el mensaje de &#39;Inicio del programa&#39; aparece en el instante 0.
2. ¿Cuántas variables &#39;m&#39; se crean en memoria?

**Ejercicio 3.** Escribir un programa que cree 5 hijos.

**Ejercicio 4.** Escribir un programa que cree 5 hijos y 3 nietos.

**Ejercicio 5.** Escribir un programa con un padre y un hijo que hagan lo siguiente:

- El hijo pide un número por teclado al usuario. Cuando ha leído el número termina.
- El padre escribe por pantalla una secuencia de números creciente desde el último número introducido por teclado (el número tiene que estar entre 0 y 255). Estará escribiendo la secuencia hasta que el hijo vuelva a leer otro número.

**Ejercicio 6.** Se tiene un array de 4 elementos y se quiere realizar un programa que crea 1 hijo y 1 nieto:

- El proceso nieto hará la suma: _Suma1 = array[0] + array[1]_
- El hijo hará la siguiente operación: _Resta2 = suma1 - array[2]_
- El padre hará la suma siguiente: _Total= Suma2 \* array[3]_
- El nieto debe pasar al hijo la suma obtenida y el hijo debe pasar al padre la suma que obtiene él. El padre la mostrara por pantalla.

Diseñar un programa que cree los 3 procesos y realice las operaciones en el orden adecuado.


**Ejercicio 7.**

Sea el siguiente programa denominado **bucle\_procesos** :
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char **argv) {

    int contador, i, pid;

    contador = atoi(argv[1]);

    i = 0;

    while (i < contador) {

        pid = fork();

        i++;

    }
    
    return 0;
    
}

```
1. Explique qué hace  y dibuje un diagrama con la jerarquía de procesos que se origina cuando se ejecuta el mandato bucle\_procesos 4.
2. Explique qué es un proceso _zombie_ y cuándo se producen.
3. ¿Se generan procesos _zombies_ al ejecutar el mandato anterior? Explique su respuesta.
4. ¿Qué ocurriría si se ejecutara bucle\_procesos 100? Explique la respuesta y modifique el programa para que se solucione el problema existente.
5. Modifique el programa anterior para que todos los procesos generados puedan compartir el archivo denominado pepe.txt. Explique su solución.
