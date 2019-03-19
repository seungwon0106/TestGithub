#include <signal.h>	//signal()
#include <stdio.h>	//printf()
#include <stdlib.h> //exit(0)
#include <unistd.h> //pause()
static void sigHandler(int sig)
{
		static int count =0;
		
		count ++;
		
		if(sig==SIGINT)
		{
			printf("Caught SIGINT (%d)\n", count);
			return;	//원래 프로그램(for문)의 상태로 돌아옴
		}
		else // if(sig == SIGQUIT)
		{
			printf("Caught SIGQUIT (%d)\n", count);
			//return;	//원래 프로그램의 상태로 돌아옴
		}

		printf("Caught SIGQUIT - that's all folks!\n");
		exit (0);
}

int main(int argc, char argv[])
{
	if(signal(SIGINT, sigHandler)==SIG_ERR)
		return -1;

	if(signal(SIGQUIT, sigHandler)==SIG_ERR)
		return-1;

	for(;;) // =while문
		pause();	//signal이 들어올때 까지 
}
