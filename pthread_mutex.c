#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>



int cnt;

pthread_mutex_t mutex_cnt;

void *inc_function(void*arg)
{
	pthread_mutex_lock(&mutex_cnt);
	printf("Before inc : %d\n", cnt);
	cnt++;	//critical section
	printf("After inc : %d\n", cnt);
	pthread_mutex_unlock(&mutex_cnt);
}

void *dec_function(void*arg)
{
	pthread_mutex_lock(&mutex_cnt);
	printf("Before dec : %d\n", cnt);
	cnt--;	//critical section
	printf("After dec : %d\n", cnt);
	pthread_mutex_unlock(&mutex_cnt);
}

int main(int argc, char *argv[])
{
	pthread_t p_thread[2];
	
	//Mutex �ʱ�ȭ
	pthread_mutex_init(&mutex_cnt, NULL);

	pthread_create(&p_thread[0], NULL, inc_function, NULL);
	pthread_create(&p_thread[1], NULL, dec_function, NULL);

	pthread_join(p_thread[0], NULL);
	pthread_join(p_thread[1], NULL);

	pthread_mutex_destroy(&mutex_cnt);
	zl
	return 0;

}