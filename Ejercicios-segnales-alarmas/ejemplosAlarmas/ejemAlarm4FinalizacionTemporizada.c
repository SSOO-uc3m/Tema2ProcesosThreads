#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pid_t pid;

void tratar_alarma(int s) {
	kill(pid, SIGKILL);
}

int main(int argc, char **argv) {
	int status;
	char **argumentos;

	struct sigaction act;
	argumentos = &argv[1];
	pid = fork();
	switch(pid) {
		case -1: /* error del fork() */
			perror ("fork");
			exit(-1);
		case 0: /* proceso hijo */
			execvp(argumentos[0], argumentos);
			perror("exec");
			exit(-1);
		default: /* padre */
			/* establece el manejador */
			act.sa_handler = tratar_alarma;
			act.sa_flags = 0;
			sigaction(SIGALRM, &act, NULL);
			alarm(5);
			wait(&status);
		}
	exit(0);
}
