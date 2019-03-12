//ex) copy a.txt b.txt

#include <stdio.h> //printf()
#include <fcntl.h> //O_RDONLY, O_WRONLY, O_RDWR
#include <unistd.h> //write(), read(), close()

#define BUF_SIZE 10

//#define DEBUG

int main (int argc, char *argv[])
{

#ifdef DEBUG
	printf("argc : %d \n",argc);
	printf("argv[1] : %s \n", argv[1]);
	printf("argv[2] : %s \n", argv[2]);

#endif

	int fd1, fd2, len;
	char buf[BUF_SIZE];

	fd1 = open(argv[1], O_RDONLY); //Open read file
	if(fd1<0)
			printf("fd1 open error\n");
	fd2 = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC); //Open write file
	if(fd2<0)
		printf("fd2 open error\n");

	//read & write
	while((len = read(fd1,buf,sizeof(buf)))>0)
			write(fd2, buf,len);

	close(fd1);
	close(fd2);

	return 0;
					
}


