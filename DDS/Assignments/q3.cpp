#include<bits/stdc++.h>
typedef unsigned long ul;
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

bool set_string(string &s1, string &s2){
		int i, index=-1,len = s1.size();
		for(int i=0; i<len; i++){
				if(s1[i]=='.'){
						index = i;
						break;
				}
		}
		if(index==0){
				s1 = "0"+s1;
		}
		if(index==-1){
				s1+=".0";
				index = s1.size()-2;
		}
		else if(index==len-1){
				s1+="0";
		}
		index=-1;
		len = s2.size();
		for(int i=0; i<len; i++){
				if(s2[i]=='.'){
						index = i;
						break;
				}
		}
		if(index==0){
				s2 = "0"+s2;
		}
		if(index==-1){
				s2+=".0";
		}
		else if(index==len-1){
				s2+="0";
		}
}

double string_to_double(int x, string s){
		int i, index;
		double x_pow,num=0;
		for(i=0; i<s.size(); i++){
				if(s[i]=='.'){
						index = i;
						break;
				}
		}
		x_pow = 1;
		for(i = index-1;i>=0;i--){
			num += char_to_num(s[i]) * x_pow;
			x_pow*=x;
		}
		x_pow = 1/(double)x;
		for(i = index+1; i<s.size();i++){
				num += char_to_num(s[i]) * x_pow;
				x_pow/=x;
		}
		return num;
}

bool check(int x, string s1, string s2, char op){
	bool found=false;
	if(x<=1 || x>35){
			return false;

	}
	for(int i=0; i<s1.size();i++){
		if(s1[i]=='.'){
			if(found){
				return false;
			}
			else{
					found=true;
					continue;
			}
		 }
		if(!((s1[i]>='0' && s1[i]<='9') || (s1[i]>='A' && s1[i]<='Z'))){
				return false;
		}
		if(char_to_num(s1[i])>=x){
				return false;
		}
	}
	found = false;
	for(int i=0; i<s2.size();i++){
		if(s2[i]=='.'){
			if(found){
				return false;
			}
			else{
					found=true;
					continue;
			}
		 }
		if(!((s2[i]>='0' && s2[i]<='9') || (s2[i]>='A' && s2[i]<='Z'))){
				return false;
		}
		if(char_to_num(s2[i])>=x){
				return false;
		}
	}
	if(!(op=='+' || op=='-' || op=='*' || op=='/')){
		return false;
	}
	return true;
}

void reverse(string &s){
    int i,j;
    char ch;
    i=0;
    j=s.size()-1;
    while(i<j){
      ch=s[i];
      s[i]=s[j];
      s[j]=ch;
      i++;
      j--;
    }
}
void enumerate()
{
	int i=0;
	while(i<=10000)
		i++;
}
int main(){
	int i, x;
	enumerate();
	unsigned long long int_res;
	double num1=0,num2=0,res=0,temp;
	char op;
	string s1,s2,result;
	cout<<"Input 2 operands in radix_x, radix_x,  and the operator(+, -, *, /)\n";
	cin>>s1>>s2>>x>>op;
	if(!check(x,s1,s2,op)){
			cout<<"Invalid input\n";
			return 0;
	}
	set_string(s1,s2);
	num1 = string_to_double(x, s1);
	num2 = string_to_double(x, s2);
	switch(op){
			case '+': res = num1+num2;
								break;
			case '-': res = num1>num2 ? num1-num2 : num2-num1;
								break;
			case '*': res = num1*num2;
								break;
			case '/': if(num2==0){
									cout<<"Operation not possible";
									return 0;
								}
								res = num1/num2;
								break;
	}
	if(res==0){
			cout<<"0.0\n";
	}
	else{
			result="";
			int_res = res;
			res-=int_res;
			if(num1<num2 && op=='-'){
				cout<<"-";
			}
			if(int_res==0){	cout<<"0";	}
			while(int_res>0){
				result+=num_to_char(int_res%x);
				int_res = int_res/x;
			}
			reverse(result);
			cout<<result<<".";
			int count = 35;
			while(res!=0 && count>0){
				count--;
				temp = x*res;
				int_res = temp;
				res = temp-int_res;
				cout<<num_to_char(int_res%x);
			}
	}
	cout<<"0\n";
	return 0;
}
