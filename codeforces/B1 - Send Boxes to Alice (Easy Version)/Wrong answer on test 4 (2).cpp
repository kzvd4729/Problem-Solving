/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/21/2019 00:09                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1254/problem/B1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],bb[N+2];
bool isPrime(int x)
{
  for(int i=2;i<x;i++)
    if(x%i==0)return 0;
  return 1;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int sm=0;
  for(int i=1;i<=n;i++)cin>>aa[i],sm+=aa[i];
  for(int i=1;i<=n;i++)bb[i]=aa[i];
   int ans=inf;
  for(int p=2;p<=sm;p++)
  {
    if(sm%p||(!isPrime(p)))continue;
    //cout<<"*"<<p<<endl;
    int now=0;
    for(int i=1;i<=n;i++)aa[i]=bb[i];
    for(int i=1;i<=n;i++)
    {
      if(aa[i]<0)
      {
        now-=aa[i];aa[i+1]+=aa[i];
      }
      else
      {
        int ex=aa[i]%p;
        if(ex<p-ex)now+=ex,aa[i+1]+=ex;
        else now+=p-ex,aa[i-1]-=(p-ex);
      }
    }
    ans=min(ans,now);
  }
  if(ans==inf)ans=-1;
  cout<<ans<<endl;
  return 0;
}