#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	FILE*write_fp; //파일 구조체 포인터를 다룸
	char buffer[BUFSIZ +1];
	sprintf(buffer, "Once upon a time, ther was ...\n");
	write_fp = popen("od -c", "w");
	if(write_fp != NULL)
	{
		fwrite(buffer, sizeof(char), strlen(buffer), write_fp);
		pclose(write_fp);
		exit(EXIT_SUCCESS);

	}
	exit(EXIT_FAILURE);

}
