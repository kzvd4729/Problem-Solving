/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/14/2020 11:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 327 ms                                          memory_used: 23500 KB                             
*  problem: https://codeforces.com/contest/449/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6,mod=1e9+7;
int dp[N+2],aa[N+2];
void sos(int n)
{
  for(int i=0;i<(1<<n);i++)dp[i]=aa[i];
  for(int i=0;i<n;i++)
  {
    for(int msk=(1<<n)-1;msk>=0;msk--)
    {
      if(!(msk&(1<<i)))
        dp[msk]+=dp[msk^(1<<i)];
    }
  }
}
void sos2(int n)
{
  for(int i=0;i<(1<<n);i++)dp[i]=aa[i];
  for(int i=0;i<n;i++)
  {
    for(int msk=(1<<n)-1;msk>=0;msk--)
    {
      if(!(msk&(1<<i)))
        dp[msk]=(dp[msk]-dp[msk^(1<<i)]+mod)%mod;
    }
  }
}
int pw[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);  
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;aa[x]++;
  }
  sos(20);pw[0]=1;for(int i=1;i<=N;i++)pw[i]=(pw[i-1]+pw[i-1])%mod;
  for(int i=0;i<(1<<20);i++)
    aa[i]=pw[dp[i]]-1;
  sos2(20);cout<<dp[0]<<endl;
  return 0;
}