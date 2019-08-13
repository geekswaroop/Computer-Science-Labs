#include<iostream>
#include<cmath>

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

int minbase(string s){
    char max=' ';
    for(int i=0; i<s.length(); i++){
        if(s[i]>max) max=s[i];
    }
    if(max>57) return (max-54);
    else return (max-47);
}

int main(){
    string s1, s2;
    int i,j;
    bool found=false;
    cin>>s1>>s2;
    for(i=minbase(s1); i<20; i++){
        for(j=minbase(s2); j<20; i++)
            if(toBaseTen(i,s1)==toBaseTen(j,s2)){
                found=true;
                break;
            }
        if(found) break;
    }
    cout<<"Bases of the two numbers are: "<<i<<" "<<j<<endl;

    return 0;
}
