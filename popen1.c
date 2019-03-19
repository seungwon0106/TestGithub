#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	//파일포인터 생성	
	FILE *read_fp;
	char buffer[BUFSIZ +1];		// 1은 널문자
	int chars_read;


//	printf("BUFSIZ = %ld \n", BUFSIZ);

//	printf("buffer size = %ld \n",sizeof(buffer));
	
	
	memset(buffer, '\0',sizeof(buffer));

	read_fp = popen("uname -a", "r");
	if(read_fp != NULL)
	{
		chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		if(chars_read >0)
		{
			printf("Output was : -\n%s\n", buffer);

		}

		pclose(read_fp);
		exit(EXIT_SUCCESS);
	}

	exit(EXIT_FAILURE);
}
