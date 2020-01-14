#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
int main()
{
	int fd;
	char *filename = "/home/student/181CO125/Lab-2/file.txt";
	char *filename2 = "/home/student/181CO125/Lab-2/file2.txt";

	//CREAT
	fd = creat(filename, S_IRWXU);
	if(fd<0)
		printf("Error\n");
	else
		printf("\nCreated file.txt\n");

	//OPEN
	fd = open(filename, O_CREAT | O_RDWR,S_IRWXU);
	if(fd<0)
		printf("Error\n");
	else
		printf("File opened.\n");
	
	//ACCESS
	//Answers can the user who invoked me have RWX permissions?
	int access_return = access(filename, F_OK);
	if(access_return!=0)
		perror("Error");
	else
		printf("\nF_OK and file exists!\n");



	//CHMOD
	//Changes mode of the given filename

	int chmod_return = chmod(filename, S_IRWXU);
	if(chmod_return!=0)
		perror("Error");
	else
		printf("File mode changed successfully\n");

	//UMASK
	//Always Successful. Returns previous mask

	int umask_return = umask(S_IWOTH);
	printf("\nPrevious Mask Value: %d\n", umask_return);

	//CHOWN
	//Changes Ownership! -1 is gid() and 1000 is uid()
	int chown_permit = chown(filename, 1000, -1);
	printf("File Ownership changed!\n");

	//EXECL
	char *binaryPath = "/bin/ls";
  	char *arg1 = "-lh";
  	char *arg2 = "/home";
 
  	execl(binaryPath, binaryPath, arg1, arg2, NULL);
 
  	

}
