//Program: grandChild_ fork
//Author: Joseph Eggers

// Purpose: of this file to run a ghild and grannd child progress the program files together.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	pid_t  pid;
	pid_t  pid_grand;
	int counter = 0;
	/* fork another process */
	pid = fork();
	
	fprintf(stderr, "This is process %d", getpid());
	fprintf(stderr, "\n");
	fprintf(stderr, "pid %d", pid);
	fprintf(stderr, "\n");

	if (pid < 0) { /* error occurred */
		fprintf(stderr, "Fork Failed");
		exit(-1);
	}
	else if (pid == 0 ) { /* child process */
		pid_grand = fork(); 
		sleep(10);
		
		if(pid_grand == 0){
			fprintf(stderr, "This is grand child process %d", getpid());
			fprintf(stderr, "\n");
			execlp("/bin/ls", "ls", NULL);

			fprintf(stderr, "This is never printed");
			fprintf(stderr, "\n");
		}
		
		else{
			fprintf(stderr, "This is child process %d", getpid());
			fprintf(stderr, "\n");
			execlp("/bin/ls", "ls", NULL);

			fprintf(stderr, "This is never printed");
			fprintf(stderr, "\n");
			printf("\n Child Complete \n");
		}
	}
	else { /* parent process */
		fprintf(stderr, "This is parent process %d", getpid());
		fprintf(stderr, "\n");
		/* parent will wait for the child to complete */
		wait(NULL);
		printf("\n Child Complete \n");
		exit(0);
	}
}