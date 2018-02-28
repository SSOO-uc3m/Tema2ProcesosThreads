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