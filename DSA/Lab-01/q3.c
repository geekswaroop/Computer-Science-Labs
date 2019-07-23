//find square root using binary search
#include<stdio.h>
#include<stdlib.h>
float sroot(int n)
{
	float start=0,end=n,mid;
	while(start<end)
	{
		mid=(start+end)/2;
		if(abs(mid*mid-n)<1e-8)
			return mid;
		else if (mid*mid>n)
			end=mid;
		else 
			start=mid;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	float ans = sroot(n);
	printf("%f",ans);
}