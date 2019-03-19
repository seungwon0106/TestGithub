#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

long  mtime(int argc, char *argv[])
{
	struct stat sb;
	time_t UTCtime;
	struct tm *tm;
//	struct timeval UTCtime_u;
	char buf[BUFSIZ];


	if(stat(argv[1], &sb)==-1)
	{
		fprintf(stderr,"Error : stat()\n");
		return -1;
	}
	time(&UTCtime);
	printf("%s", mtime(&sb.st_mtime));
	
	return mtime(&UTCtime);
}
