
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("\nUID: %d, EUID: %d, PID: %d\n", getuid(), geteuid(), getpid());
	printf("\nGID: %d, PPID: %d, EGID: %d\n", getgid(), getppid(), getegid());

	printf("Alarm clock for 5 seconds...\n");
	alarm(5);

	printf("Exiting the program after alarm clock...\n");
	sleep(5);

	exit(0);
}