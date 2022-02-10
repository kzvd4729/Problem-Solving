/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-17 00:55:02                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 199                                        memory_used (MB): 17.7                            
*  problem: https://vjudge.net/problem/LightOJ-1124
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6+10;
const long mod=100000007;
long fac[N+2],inv[N+2];
int lo[20],hi[20];
long bigmod(long b,long p,long mod)
{
  long ret=1LL;
  while(p)
  {
    if(p%2)ret=(ret*b)%mod;
    b=(b*b)%mod;p/=2;
  }
  return ret;
}
long abc(void)
{
  fac[0]=1;inv[0]=bigmod(fac[0],mod-2,mod);
  for(int i=1;i<=N;i++)
  {
    fac[i]=(fac[i-1]*i)%mod;
    inv[i]=bigmod(fac[i],mod-2,mod);
  }
}
long ncr(long n,long r)
{
  long ret=(fac[n]*inv[r])%mod;
  return (ret*inv[n-r])%mod;
}
int main()
{
  abc();int t,tc=0;scanf("%d",&t);
  while(t--)
  {
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
      scanf("%d%d",&lo[i],&hi[i]);
    int sum=0;
    for(int i=0;i<n;i++)
      sum+=lo[i];
    if(sum>m)
    {
      printf("Case %d: %d\n",++tc,0);
      continue;
    }
    sum=0;
    for(int i=0;i<n;i++)
      sum+=hi[i];
    if(sum<m)
    {
      printf("Case %d: %d\n",++tc,0);
      continue;
    }
    sum=m;
    for(int i=0;i<n;i++)
      sum-=lo[i];
    long tt=ncr(sum+n-1,n-1);
    for(int i=1;i<(1<<n);i++)
    {
      sum=m;int cnt=0;
      for(int j=0;j<n;j++)
      {
        if((i&(1<<j)))
          sum-=(hi[j]+1),cnt++;
        else sum-=lo[j];
      }
      if(sum>=0)
      {
        if(cnt%2==0)
          tt=(tt+ncr(sum+n-1,n-1))%mod;
        else tt=(tt-ncr(sum+n-1,n-1)+mod)%mod;
      }
    }
    printf("Case %d: %lld\n",++tc,tt);
  }
  return 0;
}