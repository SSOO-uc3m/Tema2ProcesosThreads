/* Este programa sirve como ejemplo del uso de threads con parámetros
  Hay que compilarlo con gcc -lpthread argvint-1.c
*/

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

void *f( void *arg){
	int *v;

	//Forma complicada de acceder a los argumentos
	int i,j,k;

	printf ("\tInicio ejecuciÃ³n del thread\n");
	i=*((int *)(arg));
	j=*((int *)(arg)+1);
	k=*((int *)(arg)+2);
	printf ("\tTH:arg con i,j,k:%d, %d, %d:\n", i,j,k);	

	//Forma simple de acceder a los argumentos
	v=(int *)arg;
	printf ("\tTH:arg con v:%d, %d, %d:\n", v[0],v[1],v[2]);	
	printf ("\tFin ejecucion el thread\n");

	pthread_exit(0);
}

int main (int argc, char *argv[]){
	pthread_attr_t attr;
	int detachstate;
	int argu[3];
	pthread_t thid;
	
	argu[0]=99;
	argu[1]=11;
	argu[2]=22;
	printf ("En el main:argu:%d, %d, %d:\n", argu[0],argu[1], argu[2]);	

	//f(argu);
        pthread_attr_init (&attr);
        //Puedes probar a crearlo DETACHED y esperar con un sleep aunque es peor opción
	if ( argc == 2 && strcmp(argv[1],"-d") ){
			pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED);
	}
	
	pthread_create (&thid, &attr, f, (void *)argu);
	pthread_attr_getdetachstate (&attr, &detachstate);
	
	pthread_join(thid,NULL);
	//sleep(2);
	exit(0);
}

