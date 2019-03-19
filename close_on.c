#include <unistd.h> //open()
#include <fcntl.h>	//O_CREAT
#include <stdio.h>

#define DEBUG

int main()

{
	int fd;
	int val;
	fd = open ("exec_copy.txt", O_CREAT|O_TRUNC,0644);
	
	val = fcntl(fd,F_GETFD,0);	//GET FD_CLOEXEC

#ifdef DEBUG
	if(val & FD_CLOEXEC)
			printf("Before : close-on-exec bit on \n");
	else
			printf("Before : close-on-exec bit off \n");
#endif

	val |= FD_CLOEXEC;	//Modify FD_CLOEXEC

#ifdef DEBUG

	if(val & FD_CLOEXEC)
			printf("Before : close-on-exec bit on \n");
	else
				printf("Before : close-on-exec bit off \n");
#endif

	fcntl(fd, F_SETFD,val);	//SET FD_CLOEXEC

#ifdef DEBUG
	if(val & FD_CLOEXEC)
			printf("Before : close-on-exec bit on \n");
	else
			printf("Before : close-on-exec bit off \n");
#endif



	
	//loop program -> exec

	execl("./loop", "./loop", (char*)0);
	//execl("ls -al", "ls -al", (char*)0);

	
	return 0;


}

