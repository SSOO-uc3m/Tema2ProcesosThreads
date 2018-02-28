#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS 10

void * func(void * param)  {
  printf("Thread %d \n", pthread_self());
  pthread_exit(0);
}

int main() {
  int j;
  pthread_attr_t attr;
  pthread_t thid[MAX_THREADS];
  pthread_attr_init(&attr);
  // el hilo independiente liberara sus recursos cuando finalice su ejecución
  pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
  
  for(j = 0; j < MAX_THREADS; j ++)
    pthread_create(&thid[j], &attr,  func, NULL);
  sleep(5);
}
