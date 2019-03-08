#include <stdio.h>
#include <unisd.h>

int main(int argc, char *argv[])
{
	printf("argc = %d\n",argc);
	printf("argv[0] = %s\n",argv[0]);
	printf("argv[1] = %s\n", argv[1]);
	sleep(10);
	return 0;
			
}

