#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//POSIX Thread
#include <pthread.h>

#include <time.h>
#include <sys/time.h>


#define DATASIZE	sizeof(int)*4

int *addr;
long long result =0;


void* cal(void * data)
{
	int i;
	long start=1;
	long end=20000;
	long value1=0;
	long value2=0;
	pthread_t t_id;

	long long argData = *((int*)data);
	t_id = pthread_self();	//자기자신의 pthread id 값 읽어옴

	//printf("getpid = %d, tid = %lu, argData = %d, glob_var=%d \n", getpid(), t_id, argData, glob_var);
	if (argData == 1)
	{
		end = end >> 1;
		for (i = start; i <= end; i++)
		{
			value1 += i;
		}
	}
	if (argData == 2)
	{
		start = (end >> 1) + 1;
		for (i = start; i <= end; i++)
		{
			value2 += i;
		}
	}

	result += (value1 + value2);
	return(void *)(result);

}

int main(void)
{
	//POSIX thread id data type;
	pthread_t p_thread[2];
	int i;
	int ret;
	int a = 1;
	int b = 2;
	long start = 1;
	long end = 20000;
	long long status;

	struct timeval startTime, endTime;
	double diffTime;
	addr = malloc(DATASIZE);

	gettimeofday(&startTime, NULL);
	
	//end = end >> 1;
	//printf("%ld\n", start);
	//printf("%ld\n", end);
	if ((ret = pthread_create(&p_thread[0], NULL, cal, (void*)&a)) < 0)
	{
		perror("Error : pthread_create1()");
		return -1;
	}
	
	
	if ((ret = pthread_create(&p_thread[1], NULL, cal, (void*)&b)) < 0)
	{
		perror("Error : pthread_create2()");
		return -2;
	}
	
	pthread_join(p_thread[1], (void**)&status);	//t_function의 return값
	printf("%lld\n", status);
	gettimeofday(&endTime, NULL);
	diffTime = (endTime.tv_sec - startTime.tv_sec) + ((endTime.tv_usec - startTime.tv_usec) / 1000000.0);
	printf("%lf s\n", diffTime);

	return 0;
}