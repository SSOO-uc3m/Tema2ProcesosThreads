# SISTEMAS OPERATIVOS

## Utilización de threads básicos

**Ejercicio 1.** Escriba un programa que permita imprimir los argumentos que recibe un thread.

**Ejercicio 2.** Realizar un programa que cree 1 thread llamador &quot;imprimir&quot; que imprime 3 veces el mensaje: &quot;Thread says hi!&quot;, duerme 1 segundo entre cada mensaje y luego indica que termina.  El programa padre del thread debe esperar hasta que termine el thread hijo.

**Ejercicio 3.** Este ejercicio muestra los problemas que existen cuando un padre y un thread hijo modifican al mismo tiempo una variable global.

Realizar un programa  que declare una variable global &quot;myglobal&quot; y  que cree 1 thread llamador &quot;imprimir\_punto&quot;.    El programa hace luego un for hasta 20 en la incrementa myglobal en 1. Luego termina imprimiendo el valor de myglobal.

La función &quot;imprimir\_punto&quot;  ejecuta un bucle 20 donde en cada vuelta se asigna el valor de myglobal a una variable auxiliar que se incrementa.  Se imprime un &quot;.&quot; por vuelta. Al terminar, duerme 1seg y guarda en myglobal el valor de la auxiliar.

Se pide:

1. a) Implementar el programa
2. b)Ejecutar el programa y ver que ocurre con el valor de myglobal. ¿Es igual si se ejecuta varias veces?


**Ejercicio 4.** Este ejercicio muestra como crear un número variable de thread, indicando el número con un argumento.   Para ello se crea una función que imprime &quot;Hello from thread&quot; y el número de thread y termina.

El padre recibe como argumento el número de threads (entero) y  ejecuta un bucle for que crea esos threads.  Después espera por a que terminen todos los threads y acaba.

**Ejercicio 5.** Realizar un programa que cree 1 thread que suma los valores que se le pasan como parámetro en un array de 10 enteros y cuando termina devuelve el valor calculado.


**Ejercicio  6.** Escriba un programa que cree 10 threads. Cada uno de ellos calcula el valor del número PI usando el método de Montecarlo y lo almacena  en la posición que le corresponde de en un array. Cuando han terminado todos los threads el programa principal calcula la media de los valores de pi almacenados en el array

**Ejercicio 7.** Realizar un programa que declare 2 funciones 1 y 2, donde se indique la identidad del thread que la está ejecutando. la función 1 se duerme 2 segundos y la 2 se duerme 5 segundos.     A continuación el programa principal debe lanzar 2 threads, uno para cada función, escribir su propiedad identidad y terminar.

Haga una nueva versión en la que el padre espere a que los hijos terminen antes de terminar.

**Ejercicio 8.** Realizar un programa que declare una función multiplicar y que le pase como parámetros 2 números. A continuación el programa principal debe preparar los parámetros del thread y lanzar 1 thread con multiplicar, escribir su propiedad identidad y terminar.

**Ejercicio 9.** Realizar un programa que declare una función multiplicar y que le pase como parámetros 2 números a multiplicar. A continuación el programa principal debe coger el número cuya tabla queremos,  y ejecutar un bucle lanzando threads que impriman su tabla de multiplicar. En cada iteración debe preparar los parámetros del thread y lanzar 1 thread con multiplicar. Al final  escribir su propiedad identidad y termina.

**Ejercicio 10.** Realizar un programa que declare una función imprimir y  que le pase como parámetros 1 string a imprimir.  A continuación el programa principal debe preparar los parámetros con 2 string &quot;hola&quot; y &quot;mundo&quot; y lanzar 2 threads que intenten imprimir &quot;hola mundo&quot; y terminar.

**Ejercicio 11.** Realizar un programa que sume valores en concurrencia usando threads. El program declara una variable global suma\_total y un procedimiento que sumar que incrementa suma\_total en 100 usando una variable local intermedia, se duerme un segundo y asigna la variable interna a suma\_total. A continuación el principal crea 10 threads sumar, espera a que terminen, imprime el valor de suma calculado y termina.

Como variante, elimine el tiempo de dormir e indique lo que ocurre.

**Ejercicio 12.** Realizar un programa que cree 1 thread que suma los valores que se le pasan como parámetro en un array de 10 enteros (1,2,3,4,5,6,7,8,9,10) y cuando termina devuelve el valor calculado.

**Ejercicio 13.** Realizar un programa que cree 10 threads. Cada thread recibe por parámetro un número n que debe imprimir por pantalla. El número n recibido estará en el rango [0-9] según el thread creado.

**Ejercicio 14.** Dado el siguiente código que realiza lo siguiente:

- Crea un número (determinado) de threads. Cada thread imprime su identificador y termina.
- El proceso padre espera con la función join la finalización de los threads.

Se pide modificar este programa para que calcule la suma de enteros generados de forma aleatoria. Primeramente cada hijo genera un número entero aleatorio y lo guarda en un array global. Cuando los hijos terminan el padre calcula la suma de todos los enteros generados por los threads y la imprime en la pantalla. Usar la función _random( )_ para generar un número aleatorio: `int numeroAleatorio = (int)(random( ) % 10);`

```

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_THREADS 10

void *funcionThread(void *numero);

int main(){
{
    int j, k; 
    pthread_t thid[MAX_THREADS]; //array con los identificadores de los threads que se van a crear
 pthread_attr_t attr; //variable con los atributos de los threads que se van a crear
 pthread_attr_init(&attr); //se inicializan los atributos (a por defecto)
 //bucle para crear los distintos threads
 for(j = 0; j < MAX_THREADS; j++)
 {
pthread_create(&thid[j], &attr, (void *)funcionThread, NULL);
 }
 //bucle para esperar por la finalización de los distintos threads
 for(k = 0; k < MAX_THREADS; k++)
 {
pthread_join(thid[k], NULL);
 }
 return(0);
}

void *funcionThread(void) 
{
 printf("Thread con identificador  = %ud \n", (int) pthread_self()); //imprime el id del thread
 pthread_exit(0); //hace que termine el thread y se mande el estado de terminación 
```
**Ejercicio 15.** Realizar un programa que cree 10 threads para sumar los datos de un fichero &quot;números.dat&quot; que contiene 1000 números enteros. Cada thread  debe sumar 100 números del fichero. El thread n sumará los números entre n\*100 y (n\*100)+99 del array (n varía de 0 a 9). Cuando terminen el programa principal escribirá la suma total.

**Ejercicio 16.** Se dispone de	un	archivo	de	texto que contiene una	lista de números enteros. El primer	valor indica cuantos números hay en	el resto del archivo. Escriba un programa que lea el archivo en	un array en memoria principal y calcule el	valor máximo utilizando varios hilos de	ejecución.	Para calcular el valor máximo se repartirá el array	en	tantas partes como hilos en ejecución y se	asignará una parte del array a cada uno de	los	hilos de ejecución.	Cada	hilo deberá	calcular el	valor máximo de	los	elementos en su	parte asignada.	Posteriormente	el	programa principal calculará el máximo global.

