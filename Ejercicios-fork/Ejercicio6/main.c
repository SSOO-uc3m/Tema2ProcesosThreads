#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main (){
  pid_t pidHijo, pidNieto;
  int array[]={1,8,3,10};
  int suma,resta,total,status;

  pidHijo = fork();
  switch (pidHijo) {
    case 0 : //hijo 
      pidNieto = fork();
      switch (pidNieto) {
          case 0: // nieto 
              suma = array[0]+array[1];
              printf ("Suma1=%d\n",suma);
              exit(suma);
          default: //hijo 
              while (pidNieto !=wait (&status));
              resta = WEXITSTATUS(status)-array[2];
              printf ("Resta2=%d\n",resta);
              exit(resta);
        }
    default: //Proceso padre
        while (pidHijo !=wait (&status));
        total = array[3]* WEXITSTATUS(status);
        printf ("Total=%d\n", total);

       return(0);
    }
}
