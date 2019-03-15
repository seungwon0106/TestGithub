#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int global = 10;
int main(void)
{

	int i=20;
	pid_t pid;
	int stauts;

	pid = fork();

	//child process
	if(pid ==0)
	{
		global = global +10;
		i = i+10;	
	}

	//parent process
	else
	{
		global = global +100;
		i=i+100;
	}

	printf("global = %d; i= %d \n", global,i);
}
