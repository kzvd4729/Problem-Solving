/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/01/2019 10:36                        
*  solution_verdict: Runtime error on test 5                 language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 7000 KB                              
*  problem: https://codeforces.com/contest/283/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],n;long dp[N+2][2];
int col[N+2][2],cy[N+2][2];
long dfs(int x,int f)
{
  if(x<=0||x>n)return 0;
  if(dp[x][f]!=-1)return dp[x][f];
  dp[x][f]=0;
  if(!f)dp[x][f]=aa[x]+dfs(x+aa[x],1);
  else dp[x][f]=aa[x]+dfs(x-aa[x],0);
  return dp[x][f];
}
int cycle(int x,int f)
{
  if(x<=0||x>n)return cy[x][f]=0;
  if(col[x][f]==1)return cy[x][f]=1;
  if(cy[x][f]!=-1)return cy[x][f];
  col[x][f]=1;int now;
  if(!f)now=cycle(x+aa[x],1);
  else now=cycle(x-aa[x],0);
  col[x][f]=2;return cy[x][f]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=2;i<=n;i++)
    cin>>aa[i];
  memset(cy,-1,sizeof(cy));
  memset(dp,-1,sizeof(dp));
  for(int i=1;i<n;i++)
  {
    cy[1][0]=-1;dp[1][0]=-1;dp[1][1]=-1;
    aa[1]=i;if(cycle(1,0))cout<<-1<<"\n";
    else cout<<dfs(1,0)<<"\n";
  }
  return 0;
}