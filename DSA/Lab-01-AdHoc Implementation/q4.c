//add 2 large positive number
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[105],b[105],ans[105];
	int i,j,k,temp,c=0;
	scanf("%s",a);
	scanf("%s",b);
	int ln1=strlen(a);
	int ln2=strlen(b);
	k=(ln1>ln2?ln1:ln2);
	ans[k]='\0';
	i=ln1-1;
	j=ln2-1;
	k--;
	while(i>=0 && j>=0)
	{
		temp=a[i--]+b[j--]-2*('0')+c;
		c=temp/10;
		ans[k--]=(temp%10)+'0';
	}
	if(ln1<ln2)
	{	while(j>=0)
		{temp=b[j--]-'0'+c;
		c=temp/10;
		ans[k--]=(temp)%10+'0';}
	}
	else if (ln1>ln2)
	{	while(i>=0)
		{temp=a[i--]-'0'+c;
		c=temp/10;
		ans[k--]=temp%10+'0';}
	}
	int p=(ln1>ln2?ln1:ln2);
	if(ln1==ln2)
	{	if(c==1)
			printf("%c",'1');
		else
			printf("%c",'0');
		for(i=0;i<=p;i++)
		{
			printf("%c",ans[i]);
		}
	}
	else
		{for(i=0;i<=p;i++)
		{
			printf("%c",ans[i]);
		}}	
}