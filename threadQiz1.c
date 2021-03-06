#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//POSIX Thread
#include <pthread.h>
#include <time.h>
#include <sys/time.h>


#define DATASIZE	sizeof(int)*4


int *addr;
//Thread function
void* cal(void * data)
{
	int i;
	int startval = 1;
	int endval = 200000;
	long long result;

	result = *((long long*)data);
	pthread_t t_id;
		
	for (i = startval; i <= endval; i++)
	{
		result += i;
	}

	return (void*)(result);

}


int main(void)
{

	//POSIX thread id data type;
	pthread_t p_thread;
	int ret, sum;
	int a;
	long long status;
	int i;
	struct timeval startTime, endTime;
	double diffTime;

	gettimeofday(&startTime, NULL);


	if ((ret = pthread_create(&p_thread, NULL, &cal, (void*)&a)) < 0)
	{
		perror("Error : pthread_create1()");
		return -1;
	}



	pthread_join(p_thread, (void**)&status);	//cal�� return��
	printf("%lld\n", status);

	gettimeofday(&endTime, NULL);
	diffTime = (endTime.tv_sec - startTime.tv_sec) + ((endTime.tv_usec - startTime.tv_usec) / 1000000.0);
	printf("%lf s\n", diffTime);
	return 0;


}