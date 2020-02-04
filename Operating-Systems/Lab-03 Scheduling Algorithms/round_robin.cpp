#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define f first
#define s second
#define int long long
#define sz(x) (ll)(x.size())
#define MAX 200005
using namespace std;

signed main(){
  cout<<"enter number of process and quant\n";
  int n,quant;
  cin>>n>>quant;
  pair<int,pair<int,int> > arr[n];
  cout<<"Enter Arrival time and burst time\n";
  for(int i=0;i<n;i++){
    cin>>arr[i].f>>arr[i].s.f;
    arr[i].s.s=i;
  }
  int burst_sort[n],arr_sort[n];
  sort(arr,arr+n);
  vector<pii> cur;
  for(int i=0;i<n;i++){
    burst_sort[arr[i].s.s]=arr[i].s.f;
    arr_sort[arr[i].s.s]=arr[i].f;
  }
  int time_exec=0;
  int done[n]={0};
  int cnt=0;
  int ans[n];
  int tmp=0;
  int cs=0;
  int prev=-1;
  vector<pii> cpu_idle;
  for(int i=0;i<n;i++){
    cur.pb(make_pair(arr[i].s.f,arr[i].s.s));
    if(time_exec<arr[i].f){
      cpu_idle.pb(make_pair(time_exec,arr[i].f));
      time_exec=arr[i].f;
    }
    // if(i<n-1) cout<<time_exec<<" "<<arr[i+1].f<<" "<<"here\n";
    while(i<n-1 and cnt!=cur.size() and arr[i+1].f>time_exec){
      if(cur[tmp].f<=quant and cur[tmp].f!=0){
        if(prev!=tmp) cs++,prev=tmp;
        ans[cur[tmp].s]=time_exec+cur[tmp].f;
        cur[tmp].f=0;
        time_exec+=cur[tmp].f;
        cnt++;
        // cout<<"gandu\n";
        tmp++;
        if(tmp==cur.size() and time_exec<arr[i+1].f) tmp=0;
        continue;
      }
      if(cur[tmp].f>0){
        // cout<<"hesa\n";
        if(prev!=tmp) cs++,prev=tmp;
        time_exec+=quant;
        cur[tmp].f-=quant;
        tmp++;
        if(tmp==cur.size() and time_exec<arr[i+1].f) tmp=0;
      }
    }
  }
  while(cnt!=n){
    for(int i=tmp;i<n;i++){
      if(cur[i].f>0 and cur[i].f<=quant){
        if(prev!=i) cs++,prev=i;
        time_exec+=cur[i].f;
        ans[cur[i].s]=time_exec;
        cur[i].f=0;
        cnt++;
      }
      else if(cur[i].f>0){
        if(prev!=i) cs++,prev=i;
        time_exec+=quant;
        cur[i].f-=quant;
      }
    }
    tmp=0;
  }
  int wait_time[n],turn_around[n];
  for(int i=0;i<n;i++){
    turn_around[i]=ans[i]-arr_sort[i];
    wait_time[i]=turn_around[i]-burst_sort[i];
  }
  for(int i=0;i<n;i++){
    cout<<turn_around[i]<<" "<<wait_time[i]<<"\n";
  }
  cout<<"context_switches are "<<cs-1<<"\n";
  cout<<"cpu idle time is\n";
  for(int i=0;i<cpu_idle.size();i++){
    cout<<cpu_idle[i].f<<" "<<cpu_idle[i].s<<"\n";
  }
}
