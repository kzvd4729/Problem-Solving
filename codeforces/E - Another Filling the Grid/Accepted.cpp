/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/29/2019 20:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 343 ms                                          memory_used: 1000 KB                              
*  problem: https://codeforces.com/contest/1228/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=250;
const long mod=1e9+7;
long ncr[N+2][N+2],n,k,dp[N+2][N+2],pw[N+2],pw1[N+2];
void NCR()
{
  for(long i=1;i<=N;i++)
    ncr[i][0]=1;
  ncr[1][1]=1;
  for(long i=2;i<=N;i++)
    for(long j=1;j<=N;j++)
      ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
}
long dfs(long row,long one)
{
  if(row>n)
  {
    if(one==n)return 1;
    return 0;
  }
  if(dp[row][one]!=-1)return dp[row][one];
  long rm=n-one;
  long now=0;
  for(long i=1;i<=one;i++)
    now=(now+((ncr[one][i]*pw1[n-i])%mod)*dfs(row+1,one))%mod;
  for(long i=1;i<=rm;i++)
    now=(now+(((ncr[rm][i]*pw1[rm-i])%mod)*pw[one])%mod*dfs(row+1,one+i))%mod;
  return dp[row][one]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  NCR();cin>>n>>k;
  if(k==1)cout<<1<<endl,exit(0);
  pw[0]=1;
  for(int i=1;i<=N;i++)pw[i]=(pw[i-1]*k)%mod;
  pw1[0]=1;
  for(int i=1;i<=N;i++)pw1[i]=(pw1[i-1]*(k-1))%mod;
   memset(dp,-1,sizeof(dp));
  cout<<dfs(1,0)<<endl;
   return 0;
}