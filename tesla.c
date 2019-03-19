#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <fcntl.h>


#define BUF_SIZE 110


int main(int argc, char **argv)
{
	int fd;
	int i, buf;

	fd = open("wtesla.c", O_RDWR | O_CREAT);
	if(fd<0)
	{
		printf("error:  ");
		exit(0);
	}
	for(i=1000; i<1010; i++)
	{
	write(fd, (void *) &i, sizeof(i));
	}
	//write(fd,"Tesla will raise the price of its after going back on a recent decision to close most of its stores.",101);

//	off_t lseek(int fd, off_t offset,34, SEEK_SET);
	lseek(fd, 0, SEEK_SET);
	read(fd, (void *)&buf,sizeof(i));
	printf("%s\n", buf);

	lseek(fd, 34*sizeof(i), SEEK_SET);
	read(fd, (void *)&buf, sizeof(i));
	printf("%s\n", buf);

	//write(fd, "vehicle",7);

		

	close(fd);
	return 0;
}
