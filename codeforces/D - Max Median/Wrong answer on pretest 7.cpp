/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/18/2021 21:42                        
*  solution_verdict: Wrong answer on pretest 7               language: GNU C++17 (64)                          
*  run_time: 109 ms                                          memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/1486/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=2e5,inf=1e9,mod=1e9+7;
 int bit[N+2];
void add(int x,int vl)
{
  for( ;x>0;x-=x&-x)bit[x]+=vl;
}
int get(int x)
{
  int ret=0;
  for( ;x<=N;x+=x&-x)ret+=bit[x];
  return ret;
}
int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  int mx=0,b=k/2+1;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];add(a[i],1);
    if(i>k)add(a[i-k],-1);
     int lo=1,hi=n,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;int g=get(md);
      if(g<b)hi=md;else lo=md;
    }
    for(md=hi;md>=lo;md--)
    {
      int g1=get(md+1),g2=get(md);
      if(g1<b&&g2>=b)mx=max(mx,md);
    }
  }
  cout<<mx<<endl;
     return 0;
}