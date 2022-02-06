/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/16/2019 20:56                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/582/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e2;
int aa[N+2],fr[N+2],bc[N+2],cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,t;cin>>n>>t;
  for(int i=1;i<=n;i++)cin>>aa[i],cnt[aa[i]]++;
  for(int i=1;i<=n;i++)
  {
    fr[i]=1;
    for(int j=1;j<i;j++)
    {
      if(aa[j]<=aa[i])
        fr[i]=max(fr[i],fr[j]+1);
    }
  }
  for(int i=n;i>=1;i--)
  {
    bc[i]=1;
    for(int j=n;j>i;j--)
    {
      if(aa[j]>=aa[i])
        bc[i]=max(bc[i],bc[j]+1);
    }
  }
  if(t==1)
  {
    int mx=0;
    for(int i=1;i<=n;i++)
      mx=max(mx,fr[i]);
    cout<<mx<<endl,exit(0);
  }
  long ans=0;
  for(int i=1;i<=n;i++)
  {
    for(int k=aa[i];k<=N;k++)
    {
      long now=(cnt[k]*1LL)*((t-2)*1LL)+fr[i];
      int mx=0;
      for(int j=1;j<=n;j++)
      {
        if(aa[j]>=k)
          mx=max(mx,bc[j]);
      }
      ans=max(ans,now+mx);
    }
  }
  cout<<ans<<endl;
  return 0;
}