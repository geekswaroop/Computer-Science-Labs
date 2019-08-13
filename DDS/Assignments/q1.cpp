#include<bits/stdc++.h>
using namespace std;



int char_to_num(char ch){
		if(ch>='0' && ch<='9'){
				return ch-'0';
		}
		else{
				return ch-'A' + 10;
		}
}

char num_to_char(int m){
		if(m>=0 && m<=9){
				return '0'+m;
		}
		else{
				return 'A'+m-10;
		}
}

bool check(int x, char s[], int y){
	if(x<=1 || x>35){
			return false;
	}
	if(y<=1 || y>35){
			return false;
	}
	for(int i=0; i<strlen(s);i++){
		if(!((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='Z'))){
				return false;
		}
		if(char_to_num(s[i])>=x){
				return false;
		}
	}
	return true;
}

void enumerate()
{
	int i=0;
	while(i<=1000)
	{
		i++;
	}
	
}
void reverse(char str[]){
    int i,j;
    char ch;
    i=0;
    j=strlen(str)-1;
    while(i<j){
      ch=str[i];
      str[i]=str[j];
      str[j]=ch;
      i++;
      j--;
    }
}

int main(){
	enumerate();
	int k, l, x, y, x_pow;
	long num=0;
	char s1[6],s2[30];
	memset(s2,'\0',30*sizeof(s2[0]));
	cin>>x>>s1>>y;
	if(!check(x,s1,y)){
			cout<<"Invalid input\n";
			return 0;
	}
	reverse(s1);
	x_pow = 1;
	for(k=0;k<strlen(s1);k++){
			num += char_to_num(s1[k]) * x_pow;
			x_pow*=x;
	}
	if(num==0){
			cout<<"0";
	}
	else{
			l = 0;
			while(num>0){
				s2[l]=num_to_char(num%y);
				num=num/y;
				k++;
			}
			reverse(s2);
			cout<<s2;
	}
	return 0;
}
