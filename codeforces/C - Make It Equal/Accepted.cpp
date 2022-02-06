/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/11/2018 21:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/1065/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
long bit[N+2];
void upd(long x,long vl)
{
  for( ;x<=N;x+=x&-x)
    bit[x]+=vl;
}
long qry(long x)
{
  long ret=0;
  for( ;x>0;x-=x&-x)
    ret+=bit[x];
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,k;cin>>n>>k;
  for(long i=1;i<=n;i++)
  {
    long x;cin>>x;
    upd(1,1);upd(x+1,-1);
  }
  long pre=0,ans=0;
  for(long i=N;i>=1;i--)
  {
    long sm=qry(i);
    if(sm==n)
    {
      if(pre)ans++;
      cout<<ans<<endl,exit(0);
    }
    if(sm+pre>k)ans++,pre=sm;
    else pre+=sm;
  }
  return 0;
}