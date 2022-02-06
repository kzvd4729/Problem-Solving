/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/19/2018 02:19                        
*  solution_verdict: Time limit exceeded on test 13          language: GNU C++17                               
*  run_time: 4000 ms                                         memory_used: 146500 KB                            
*  problem: https://codeforces.com/contest/895/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
const long mod=1e9+7;
long n,fac[N+2],xx,cnt,mp[77];
long ans,fr[77],arr[77],fsk[77];
int dp[71][(1<<19)];
bool prime(long x)
{
  for(long i=2;i<x;i++)
    if(x%i==0)return false;
  return true;
}
long factorial(void)
{
  fac[0]=1;
  for(long i=1;i<=N;i++)
    fac[i]=(fac[i-1]*i)%mod;
}
void factorize(void)
{
  for(long i=2;i<=70;i++)
  {
    long tmp=i;
    for(long j=2;j<=i;j++)
    {
      while(tmp%j==0)
      {
        fsk[i]=fsk[i]^(1<<mp[j]);
        tmp/=j;
      }
    }
    if(tmp!=1)
      fsk[i]=fsk[i]^(1<<mp[tmp]);
  }
}
long bigmod(long b,long p,long mod)
{
  long ret=1;
  while(p)
  {
    if(p%2)ret=(ret*b)%mod;
    b=(b*b)%mod;
    p/=2;
  }
  return ret%mod;
}
long ncr(long nn,long rr)
{
  long tmp=(fac[nn]*bigmod(fac[nn-rr],mod-2,mod))%mod;
  tmp=(tmp*bigmod(fac[rr],mod-2,mod))%mod;
  return tmp;
}
long calev(long xx)
{
  long sum=0;
  for(long i=0;i<=xx;i+=2)
    sum=(sum+ncr(xx,i))%mod;
  return sum;
}
long calod(long xx)
{
  long sum=0;
  for(long i=1;i<=xx;i+=2)
    sum=(sum+ncr(xx,i))%mod;
  return sum;
}
long dfs(long st,long msk)
{
  if(st>n)
  {
    if(msk==0)return 1;
    else return 0;
  }
  if(dp[st][msk]!=-1)return dp[st][msk]*1LL;
  long here=0;
  here=(calev(fr[arr[st]])*dfs(st+1,msk))%mod;
  here=(here+(calod(fr[arr[st]])*dfs(st+1,msk^fsk[arr[st]]))%mod)%mod;
  return dp[st][msk]=(int)here;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   factorial();
  cnt=-1;
  for(long i=2;i<=70;i++)
    if(prime(i))mp[i]=++cnt;
  factorize();
   cin>>n;
  for(long i=1;i<=n;i++)
  {
    cin>>xx;
    fr[xx]++;
  }
  n=0;
  for(long i=1;i<=70;i++)
    if(fr[i])arr[++n]=i;
  for(long i=1;i<=n;i++)
   memset(dp,-1,sizeof(dp));
   cout<<dfs(1,0)-1<<endl;
   return 0;
}