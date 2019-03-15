#include <stdio.h>		//printf()
#include <unistd.h> 		//fork()
#include <sys/types.h>		//pid_t

int main(void)
{

	pid_t pid;
	int x = 0;
	int status;

	if((pid = fork())==0)	//자식proc
	{			
		printf("pid = %ld, I am Process %ld, getppid =  %ld\n", (long)pid,(long)getpid(), (long)getppid());
		sleep(1);
		printf("Done\n");
		return 0;
	}
	else 
		printf("pid = %ld, I am Process %ld\n", (long)pid,(long)getpid());

	wait(&status);	//자식proc가 종료될때 까지 wait();	

	return 0;


}


