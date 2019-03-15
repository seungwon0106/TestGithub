#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

#define MYTIME 20
int main()
{
	pid_t pid;
	char *message;
	int n;
	int status;
	
	printf("fork program stating\n");
	pid = fork();

	switch(pid)
	{
		case -1: perror("fork failed");
				 exit(1);
		case 0: message = ("this is the child");
				n=5;
				break;
		default: message =( "this is the parent");
				 n=3;
				 break;
	
	}
		for(;n>0;n--)
		{
			puts(message);
			sleep(1);				
		}

	if(pid>0)
	{
		printf("Child Proc State : Zombie, about %d sec\n", MYTIME);
		sleep(MYTIME);
		wait(NULL);
		

	}


	wait(&status);
	exit(0);

}
