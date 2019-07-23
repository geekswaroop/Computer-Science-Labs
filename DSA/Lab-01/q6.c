//find the number of bits required to represent an integer
#include<stdio.h>
#include<math.h>
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	while(n>0)
	{
		n=n>>1;
		ans++;
	}
	printf("%d",ans);
}