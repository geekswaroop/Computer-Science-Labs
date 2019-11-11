//finding the dictionary order given the alphabets
// GIVE INPUT AS A CONTINOUS STRING. DO NOT PRESS ENTER. HAVEN'T TAKEN CARE OF BUFFER.
#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j,ans=0;
	scanf("%d",&n);
	char alphabets[n+5];
	char key[n+5];
	for(i=0;i<n;i++)
	{
		scanf("%c",&alphabets[i]);
	}
	scanf("%s",key);
	i=0,j=0;
	//lna=strlen(alphabets);
	int lnk=strlen(key);
	while(i<n && j<lnk)
	{
		if(alphabets[i]==key[j])
		{
			ans+=1;
			j++;
			i++;
		}
		else
		{
			ans+=(1<<(n-i-1));
			i++;
		}
	}
	printf("%d\n",ans);
}