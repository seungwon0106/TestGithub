#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//dxternal variable in initialized data
int glob =6;
char buf[] = "a write to stdout\n";

int main(void)
{
//automatic variable on the stack
	int var;
	pid_t pid;
	var = 88;

	if(write(STDOUT_FILENO,buf, sizeof(buf)-1) != sizeof(buf)-1)
			perror("write error");
	printf("before fork\n");

	//자식프로세스 생성 & 자식 프로세스인 경우
	if((pid = fork())==0)
	{
		glob++;
		var++;
	}
	else	//부모 프로세스인 경우 
	{
		sleep(2);
	}

	printf("pid = %d, glob = %d, var = %d\n", getpid(), glob,var);
	exit(0);




}

