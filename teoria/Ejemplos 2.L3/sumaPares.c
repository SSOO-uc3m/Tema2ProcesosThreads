#include <stdio.h>
#include <pthread.h>

struct sumapar {
  int n, m, r;
};

typedef struct sumapar sumapar_t;

//Función que ejecuta cada hilo que suma 
// los números pares de n a m y los guarda en r 
void suma(sumapar_t * par) {
  int i;
  int suma=0;
  
  for (i=par->n;i<=par->m;i++) {
    suma +=i;
  }
  par->r=suma;
}

int main() {
  pthread_t th1, th2;
  sumapar_t s1 = {1,50,0}; // números del 1 al 50
  sumapar_t s2 = {51,100,0}; // números del 51 al 100

  pthread_create(&th1, NULL, (void*)suma, (void*)&s1);
  pthread_create(&th2, NULL, (void*)suma, (void*)&s2);

  pthread_join(th1, NULL);
  pthread_join(th2, NULL);

  printf("Suma=%d\n",s1.r+s2.r);
    
}