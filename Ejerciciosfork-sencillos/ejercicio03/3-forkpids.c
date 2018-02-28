#include <stdio.h>
main (){
int i=3,pid;

printf ("%d\n",i);
pid=fork();
if (pid==0) {//hijo
  i++;
  printf ("Hijo %d, mipid es %d, el pid de mi padre es %d\n", i, getpid(),getppid());
}
else
  printf ("Padre %d, mipid es %d, el pid de mi padre es %d\n", i, getpid(),getppid());

}

