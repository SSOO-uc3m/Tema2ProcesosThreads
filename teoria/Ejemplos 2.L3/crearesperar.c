#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void * thread_function(void *arg)
{
  int i;
  printf("hilo:ola k ase!\n");
  sleep(1);
  printf("hilo:me piro vampiro\n");
  return NULL;
}
int main(int argc, char ** argv) {
  pthread_t mythread;    
  if (pthread_create(&mythread,
    NULL,thread_function,NULL)==-1){
      printf("error creando hilo "); 
      abort(); 
  } 
   
printf("Esperando al hilo\n"); 
  if(pthread_join(mythread,NULL)==-1){
  printf("error uniendo hilo");
  abort();
  }
 exit(0);
}
