//finding the circular numbers
#include<stdio.h>
int main()
{
	int n,carry=0,len=1,i;
	scanf("%d",&n);
	int a[1001];
	a[0]=n;
	while(a[len-1]!=1 || carry!=0)
	{
		a[len]=(a[len-1]*n+carry)%10;
		carry=(a[len-1]*n+carry)/10;
		len++;
	}
	for(i=len-1;i>=0;i--)
	{
		printf("%d",a[i]);
	}

}