// Find the longest increasing subsequence in an array which is monotonous
#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	int a[n+5],lis[n+5];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
		lis[i]=1;
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[i]>a[j] && lis[i]<lis[j]+1)
				lis[i]=lis[j]+1;
		}
	}
	int ans=1;
	for(i=0;i<n;i++)
	{
		if(lis[i]>ans)
			ans=lis[i];
	}

	printf("%d",ans);
}

