#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>
#include <unistd.h>


int main(void)
{
	pid_t pid;
	sigset_t set; 
	char SIGUSR1, SIGUSR2;

	pid = fork();
	if(pid ==-1)
	{
		printf("Error : fork pid = -1\n");
		return -1;
	}
	else if(pid ==0)
	{	
	
		sigemptyset(&set);
		sigaddset(&set,SIGUSR1 );
	}

}


