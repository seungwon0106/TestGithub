#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h> // getimeofday( ) 함수에서 사용
#include <pwd.h>	//getpwuid
#include <grp.h>
#include <pwd.h>


void access_perm(char *perm, mode_t mode)
{

		int i;
		char permchar[] = "rwx";
		memset(perm,'-',10);
		perm[10]='\0';

		if (S_ISDIR(mode))perm[0] = 'd';
		else if (S_ISCHR(mode)) perm[0] = 'c';
		else if (S_ISBLK(mode)) perm[0] = 'b';
		else if (S_ISFIFO(mode)) perm[0] = 'p';
		else if (S_ISLNK(mode)) perm[0] = 'l';
		for (i=0; i<9;i++)
		{
			if((mode << i) & 0x100)
				perm[i+1] = permchar[i%3];
		}
	
		if (mode & S_ISUID) perm[3] = 's';
		if (mode & S_ISGID) perm[6] = 's';
		if (mode & S_ISVTX) perm[9] = 't';

}


int main (int argc, char *argv[])
{
	

	uid_t uid = getuid();
	gid_t gid = getgid();
 	struct passwd *pw=getpwuid(uid);
	struct group *gw=getgrgid(gid);

	struct stat sb;	
	struct tm *tm;
	char timebuf[BUFSIZ];
	DIR *dp;
	struct stat statbuf;
	struct dirent *dent;
	char perm[11];
	char buf[100];
	char pathname[80];

	if(argc<2)
			exit(1);

	stat(argv[1], &statbuf);
	if(!S_ISDIR(statbuf.st_mode))
	{
		fprintf(stderr, "%s is not directory\n",argv[1]);
		exit(1);
	}
	if((dp = opendir(argv[1]))==NULL)
	{
		perror("ERROR:");
		exit(1);
	}
	printf("Lists of Directory(%s):\n", argv[1]);

	while((dent = readdir(dp)) != NULL)
	{
		

		sprintf(pathname, "%s/%s", argv[1], dent->d_name);
		lstat(pathname, &statbuf);
		access_perm(perm, statbuf.st_mode);
		
		if(stat(argv[1], &sb)==-1)
		{
			fprintf(stderr, "Error : stat()\n");
			return -1;
		}
				
		tm=localtime(&statbuf.st_mtime);
		//tm= mtime(&sb.st_mtime);
		//tm = localtime(&sb.st_atime);
		strftime(buf, sizeof(buf), "%m %e %H:%M", tm);
		
		printf("%s %s %s %12ld %s %s\n", perm, pw->pw_name, gw->gr_name, statbuf.st_size,buf, dent->d_name);
	

	}
	
	return closedir(dp);
}
