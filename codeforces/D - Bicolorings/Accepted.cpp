/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/20/2018 22:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 529 ms                                          memory_used: 141800 KB                            
*  problem: https://codeforces.com/contest/1051/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e3,mod=998244353;
long n,k,dp[N+2][N+N+2][3][3];
long dfs(long st,long cm,long up,long dw)
{
  if(st>n)
  {
    if(cm==k)return 1;
    else return 0;
  }
  if(dp[st][cm][up][dw]!=-1)return dp[st][cm][up][dw];
  long here=0;
  for(long i=0;i<=1;i++)
  {
    for(long j=0;j<=1;j++)
    {
      if(i==j)
      {
        if(i==up||i==dw)
        {
          here=(here+dfs(st+1,cm,i,j))%mod;
        }
        else
        {
          here=(here+dfs(st+1,cm+1,i,j))%mod;
        }
      }
      else
      {
        if(i==up&&j==dw)
        {
          here=(here+dfs(st+1,cm,i,j))%mod;
        }
        else if(i==up)
        {
          here=(here+dfs(st+1,cm+1,i,j))%mod;
        }
        else if(j==dw)
        {
          here=(here+dfs(st+1,cm+1,i,j))%mod;
        }
        else
        {
          here=(here+dfs(st+1,cm+2,i,j))%mod;
        }
      }
    }
  }
  return dp[st][cm][up][dw]=(here)%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;memset(dp,-1,sizeof(dp));
  cout<<dfs(1,0,2,2)<<endl;
   return 0;
}