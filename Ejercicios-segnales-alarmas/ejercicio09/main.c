#include <signal.h>
int sistema (char *nombre, char *argv)
{
	int pid, status, (*del)(), (*quit)();

	/* padre ignora senyales y */
    /* recupera nombres de rutinas de tratamiento de señales */
	/* para que el mandato se ejecute con el mismo tratamiento de */
	/* señales que había antes de llamar a la función. Es importante */
	/* recordar que las señales que estén capturadas pasaran a tener */
	/* asociadas la acción por defecto después del execvp /*
	del = signal (SIGINT, SIG_IGN);		 
	quit = signal (SIGQUIT, SIG_IGN);		

	pid=fork();
	switch (pid)
	{
		case 0:
			signal (SIGINT, del);
			signal (SIGQUIT, quit);
				.
			/* no se conservan después del execv */
			execvp (nombre, argv);
			perror ("al hacer exec");
				.
			/* si el hijo no puede ejecutar el programa */
			exit (1);
		case -1:
			/* fallo del fork() */
			status = -1;
			break;
		default:
			/* padre espera el fin del hijo */
			wait(&status);
	}
	signal (SIGINT, del);
	signal (SIGQUIT, quit);
	return(status);
}
