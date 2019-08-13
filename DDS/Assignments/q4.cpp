#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int toBaseTen(int b1, string s){
    int i,num=0,d;
    bool neg=false;
    if(s[0]=='-') neg=true;
    i = (neg==true)?1:0;
    d = s.length()-i-1;
    for(; i<s.length(); i++){
        if(s[i]<58)
            num+=(int)pow(b1,d)*(s[i]-48);
        else
            num+=(int)pow(b1,d)*(s[i]-55);
        d--;
    }
    if(neg==true) return num*(-1);
    else return num;
}

char* tenToBaser(int num, int base, char* ans){
    int i=0,coeff,temp,power=0;
    while((int)pow(base,power)<=num) power++;
    power--;
    while(power>=0){
        coeff=0;
        temp = (int)pow(base,power);
        while(num>=temp){
            coeff++;
            num-=temp;
        }
        if(coeff<10)
            ans[i]=coeff+48;
        else
            ans[i]=coeff+55;
        i++;
        power--;
    }
    ans[i]='\0';
    return ans;
}

void addZeros(string s, char* ans){
    int i,diff=s.length()-strlen(ans);
    for(i=strlen(ans); i>=0; i--)
        ans[i+diff]=ans[i];
    for(i=0; i<diff; i++)
        ans[i]='0';
}

int main(){
    int base,i,num;
    string s;
    char rCom[50],r_1Com[50];
    cin>>base>>s;
    tenToBaser((int)pow(base,s.length())-toBaseTen(base,s),base,rCom);
    addZeros(s, rCom);
    cout<<base<<"\'s Complement: "<<rCom<<"\n";
    tenToBaser((int)pow(base,s.length())-toBaseTen(base,s)-1,base,r_1Com);
    addZeros(s,r_1Com);
    cout<<base-1<<"\'s Complement: "<<r_1Com<<"\n";
    return 0;
}
