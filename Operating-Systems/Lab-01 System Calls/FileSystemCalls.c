#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
int main()
{
	int fd;
	char *filename = "/home/student/Documents/181CO125/file.txt";
	char *filename2 = "/home/student/Documents/181CO125/file2.txt";


	//CREAT
	fd = creat(filename, S_IRWXU);
	if(fd<0)
		printf("Error in creating a file\n");
	else
		printf("Created a file.txt successfully\n");

	//OPEN
	fd = open(filename, O_CREAT | O_RDWR, S_IRWXU);
	if(fd<0)
		printf("Error in opening a file\n");
	else
		printf("Opened file.txt successfully\n");

	//WRITE
	char *str = "Hello! I'm trying out some system calls";
	int size_wrote = write(fd, str, strlen(str));
	if(size_wrote<0)
		perror("Error");
	else
		printf("Wrote \"%s\" to file of size %d bytes\n", str, size_wrote);

	//LSEEK
	lseek(fd, 0, SEEK_SET);

	//READ
	char buf[100];
	int size_read = read(fd, buf, 100);
	buf[size_read]='\0';
	if(size_read<0)
		perror("Error");
	else
		printf("Successully read \"%s\" from file of %d size\n", buf, size_read);

	//Dup
	int new_fd = dup(fd);
	if(new_fd<0)
		perror("Error");
	else
		printf("Old descriptor %d, new descriptor %d\n", fd, new_fd);
	//LINK
	int linked = link(filename, filename2);
	if(linked!=0)
	{
		perror("Error");
	}
	else
	{
		printf(" link created successfully\n");
		//UNLINK
		int unlink_fd = unlink(filename2);
		if(unlink!=0)
			perror("Error");
		else
		{
			printf("Unlinked successfully\n");

		}


	}

	//ACCESS
	int accessed = access(filename, F_OK);
	if(accessed<0)
		perror("Error");
	else
		printf("File %s can be accessed\n", filename);

	//CHMOD
	int chmod_permission = chmod(filename, S_IRWXG| S_IRWXU);
	if(chmod_permission!=0)
		perror("Error");
	else
		printf("Permissions to the file working well!\n");

	
}