#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
int main()
{	
	pid_t pid = getpid();
	printf("\nKilling process with PID : %d\n", pid);
	kill(pid, 0);

	char *directory = "/home/student/181CO125/Lab-2/";
	chdir(directory);
	printf("\nDirectory changed to %s\n\n", directory);
}