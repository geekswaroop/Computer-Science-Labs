// CPP program to illustrate 
// default Signal Handler 
#include<stdio.h> 
#include<signal.h> 

void handle_sigint(int sig) 
{ 
    printf("Caught signal %d\n", sig); 
    exit();
} 
int main() 
{ 
	signal(SIGINT, handle_sigint); 
	while (1) 
	{ 
		printf("hello world\n"); 
		sleep(1); 
	} 
	return 0; 
} 
