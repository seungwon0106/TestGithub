#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	int data_processed;
	int file_pipes[2];	//(내기준)fd[1] 나가는것, fd[0] 들어오는것
	const char some_data[] = "123";	//파이프에 입력
	char buffer[BUFSIZ +1];

	memset(buffer, '\0', sizeof(buffer));	//buffer 값 초기화

	if(pipe(file_pipes) ==0)
	{
		data_processed = write(file_pipes[1], some_data, strlen(some_data));
		printf("Wrote %d bytes\n", data_processed);
		data_processed = read(file_pipes[0], buffer, BUFSIZ);
		printf("READ %d bytes : %s \n", data_processed, buffer);
		exit(EXIT_SUCCESS);


	}

		exit(EXIT_FAILURE);

}
