#include <signal.h>
#include <stdio.h>

void capturaSenal1 (int s){
	  printf ("Ha llegado la señal: %d\n",s);
          printf ("tiempo:%d\n", time(NULL));
}
void muerteHijo (int s){
	  printf ("Ha terminado el hijo: %d\n",s);
          printf ("tiempo:%d\n", time(NULL));
}
main (){
int i;
struct sigaction sa1,sa2;

  if (fork() == 0){
   // for (i=0; i<10; i=i+2){
      sleep (60);
      kill ( getppid(), SIGUSR1);
//    }
    sleep(3);
  }
  else {
    sa1.sa_handler=capturaSenal1;
    sa1.sa_flags=0;
    sigemptyset(&(sa1.sa_mask));
    sigaction (SIGUSR1, &sa1,NULL);

    sa2.sa_handler=muerteHijo;
    sa2.sa_flags=0;
    sigemptyset(&(sa2.sa_mask));
    sigaction (SIGCHLD, &sa2,NULL);


    pause(); // == sleep(999999)
    pause(); // == sleep(999999)
    printf (Ò%s \nÓ, ÒSE„AL RECIBIDAÓ );
  }
}
