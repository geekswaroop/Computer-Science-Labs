#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>

int main()
{
    int fd;
    char* filename = "/home/student/181CO125/file.txt";
    char* filename2 = "/home/student/181CO125/file2.txt";

    //CREAT
    //S_IRWXU means user had Read, Write, and Execute permission
    fd = creat(filename, S_IRWXU);
    if(fd<0)
        perror("Error");
    else
    {
        printf("File created and opened successfully with fd number: %d\n", fd);
    }
    //OPEN
    fd = open(filename, O_CREAT | O_RDWR, S_IRWXU);
    if(fd<0)
        perror("Error");
    else
    {
        printf("\nFile opened successfully with fd = %d\n", fd);     
    }
    
    //CLOSE
    int close_value = close(fd);
    if(close_value!=0)
        perror("Error");
    else
    {
        printf("\nFile Closed Successfully\n");
    }
    //Opening file again for READ operations
    fd = open(filename, O_CREAT | O_RDWR, S_IRWXU);
    if(fd<0)
        perror("Error");
    else
    {
        printf("\nFile opened successfully with fd = %d\n", fd);     
    }
    
    //READ
    char buf[100];
    int size_read = read(fd, buf, 100); //Reads 100 bytes from the buf
    buf[size_read]='\0';
    if(size_read<0)
         perror("Error");
    else
    {
        printf("\n%d bytes of %s File successfully read\n", size_read, buf);
    }

    //WRITE, writes to a File Descriptor
    char str[] = "Hello! Working with write functions!";
    int size_written = write(fd,str,strlen(str));

       printf("Content \"%s\" written to file of size %d bytes.\n", str, size_written);

    
    //LSEEK
    lseek(fd,0,SEEK_SET);

    //DUP
    int duplicated = dup(fd);
    if(duplicated<0)
        perror("Error");
    else
    {
        printf("\nOld FD=%d, New FD=%d\n", fd ,duplicated);
    }
    //LINK
	int link_value = link(filename, filename2);
	if(link_value!=0)
		perror("\nError");
	else
	{
		printf("\nLink created successfully\n");

		//UNLINK
		int stat = unlink(filename2);
		if(stat == 0)
			printf("Link removed successfully\n\n");
		else
			perror("\nError");
    //ACCESS
	int exists = access(filename, F_OK);
	if(exists < 0)
		perror("error");
	else
        printf("File \"%s\" exists\n", filename);
}

}