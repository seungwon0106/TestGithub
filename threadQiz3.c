#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//POSIX Thread
#include <pthread.h>


#include <time.h>
#include <sys/time.h>


#define DATASIZE	sizeof(int)*4

struct num
{
	long long startval;
	long long endval;
};

int *addr;

//Thread function
void* cal(void * data)
{
	int i;
   	long long result=0;
	struct num num2= *((struct num *)data);
	printf("startval : %lld\n", num2.startval);
	//long long endval = *((int *)data);
	printf("endval : %lld\n", num2.endval);
	pthread_t t_id;
		
	for (i = num2.startval; i <= num2.endval; i++)
	{
		result += i;
	}
		
	return (void*)(result);

}


int main(int argc, char **argv)
{

	//POSIX thread id data type;
	pthread_t p_thread;
	int ret, sum;
	struct num num1;
	num1.startval = atoi(argv[1]);
	num1.endval = atoi(argv[2]);
	long long status;
	int i;
	struct timeval startTime, endTime;
	double diffTime;

	gettimeofday(&startTime, NULL);


	if ((ret = pthread_create(&p_thread, NULL, &cal, (void*)&num1)) < 0)
	{
		perror("Error : pthread_create1()");
		return -1;
	}

	//if ((ret = pthread_create(&p_thread, NULL, &cal, (void*)&b)) < 0)
	//{
	//	perror("Error : pthread_create1()");
	//	return -1;
	//}

	pthread_join(p_thread, (void**)&status);	//calÀÇ return°ª
	printf("%lld\n", status);

	gettimeofday(&endTime, NULL);
	diffTime = (endTime.tv_sec - startTime.tv_sec) + ((endTime.tv_usec - startTime.tv_usec) / 1000000.0);
	printf("%lf s\n", diffTime);
	return 0;

}
