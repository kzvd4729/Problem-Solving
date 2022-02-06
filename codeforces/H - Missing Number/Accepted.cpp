/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/11/2019 20:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/102215/problem/H
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3,inf=1e9;
int cnt[2],aa[N+2];
int cal(int n,int ans,int d)
{
  //if(d==0)cout<<"ans= "<<ans<<endl;
  int one=0;
  for(int i=0;i<=n;i++)
  {
    int f=0;
    for(int j=0;j<=d;j++)
    {
      if((i&(1<<j))!=(ans&(1<<j)))f=1;
    }
    if(!f)one+=(bool)(i&(1<<(d+1)));
  }
  return one;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  int m=31-__builtin_clz(n);
   //cout<<m<<endl;
  vector<int>u,v;int lt=0,rt=n;
  for(int i=1;i<=n;i++)u.push_back(i);
   int ans=0,d=-1;int ask=0;
  for(int j=0;j<=m;j++)
  {
    //if(u.size()==0)assert(0);
     cnt[0]=0,cnt[1]=0;
    for(auto x:u)
    {
      ask++;if(ask>2*n+19)assert(0);
      cout<<"? "<<x<<" "<<j<<endl;
      int c;cin>>c;cnt[c]++;aa[x]=c;
    }
    int on=cal(n,ans,d);//cout<<"*"<<on<<endl;
    d++;
        int tr=0;if(on>cnt[1])tr=1;
    ans|=(tr<<j);
     v.clear();
     for(auto x:u)
      if(aa[x]==tr)v.push_back(x);
    u=v;
  }
  cout<<"! "<<ans<<endl;
  return 0;
}