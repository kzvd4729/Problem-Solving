/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/16/2019 21:06                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/582/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=3e2;
long aa[N+2],fr[N+2],bc[N+2],cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,t;cin>>n>>t;
  for(long i=1;i<=n;i++)cin>>aa[i],cnt[aa[i]]++;
  for(long i=1;i<=n;i++)
  {
    fr[i]=1;
    for(long j=1;j<i;j++)
    {
      if(aa[j]<=aa[i])
        fr[i]=max(fr[i],fr[j]+1);
    }
  }
  for(long i=n;i>=1;i--)
  {
    bc[i]=1;
    for(long j=n;j>i;j--)
    {
      if(aa[j]>=aa[i])
        bc[i]=max(bc[i],bc[j]+1);
    }
  }
  if(t==1)
  {
    long mx=0;
    for(long i=1;i<=n;i++)
      mx=max(mx,fr[i]);
    cout<<mx<<endl,exit(0);
  }
  long ans=0;
  for(long i=1;i<=n;i++)
    ans=max(ans,fr[i]+bc[i]+(fr[aa[i]]*1LL)*(t-2));
  cout<<ans<<endl;
  return 0;
}