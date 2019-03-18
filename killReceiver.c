#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigHandler(int sig)
{
	printf("KillTest : I got signal \n");
	(void)signal(SIGINT, SIG_DFL);
}

int main(void)
{
	signal(SIGINT, sigHandler);
	while(1)
	{
			printf("Hello World\n");
			sleep(1);
	}
	
}
