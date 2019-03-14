#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main (int argc, char *argv[])
{
	struct stat sb;


	if(argc!=2)
	{
		printf("Usage : %s <pathname>\n", argv[0]);
	}

	if(stat(argv[1], &sb)==-1)
	{
		fprintf(stderr,"Error : stat()\n");
		return -1;	
	}

	printf("===========================================\n");
	printf("File Type : ");

	switch(sb.st_mode & S_IFMT)
	{
		case S_IFBLK: printf("block device\n");	break;
		case S_IFCHR: printf("char device\n");	break;
		case S_IFDIR: printf("directory\n");	break;
		case S_IFIFO: printf("FIFO\n");			break;
		case S_IFLNK: printf("symlink\n");		break;
		case S_IFREG: printf("regular file \n"); break;
		case S_IFSOCK: printf("socket\n"); 		break;
		default:	  printf("unknown?\n");		break;
	}

	printf("I-node number:                 	    %ld\n", (long)sb.st_ino);
	printf("Mode :							    %lo(octal)\n", (unsigned long) sb.st_mode);
	printf("Link Count : 						%ld\n", (long)sb.st_nlink);
	printf("Ownership : 						UID=%ld  GID= %ld\n", (long) sb.st_uid, (long) sb.st_gid);
	printf("Preferred I/O block size :   		%ld bytes\n",     (long) sb.st_blksize);
	printf("Flie size : 						%lld bytes\n",		  (long long) sb.st_size);
	printf("Block allocated : 					%lld\n", 			  (long long) sb.st_blocks);
	printf("Last status change :				%s", ctime(&sb.st_ctime));
	printf("Last file access: 					%s", ctime(&sb.st_atime));
	printf("Last file modification : 			%s", ctime(&sb.st_mtime));


	return 0;
}
	