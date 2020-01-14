#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 


	fork(); 
	fork();
	printf("Hello world!\n"); 
	return 0; 
} 
