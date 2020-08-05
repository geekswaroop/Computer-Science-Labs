/*Sum of Natural Numbers
using for loop*/

#include <stdio.h>
int main () {
	int n, i, sum = 0;
	printf("Enter a positive integer: ");
	scanf("%d", &n);

	//loop starts here
	for (i = 1; i <= n; ++i) {
		sum += i;
	}
	printf("Sum = %d", sum);
	return 0;
}
