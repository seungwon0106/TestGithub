#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pwd.h>

int main()
{

//	uid_t uid;
	struct passwd *pw;
	
//	uid = getuid();
	while(	pw = getpwent())
	{
	printf("user name : %s \n",pw->pw_name);
	printf("user id : %d \n",pw->pw_uid);
	printf("grup id : %d \n",pw->pw_gid);
	printf("home directory : %s \n",pw->pw_dir);
	}
	endpwent();

	return 0;

}
