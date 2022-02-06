/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/01/2019 10:23                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 5500 KB                              
*  problem: https://codeforces.com/contest/283/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],n;long dp[N+2][2];
int col[N+2],cy[N+2];
long dfs(int x,int f)
{
  if(x<=0||x>n)return 0;
  if(dp[x][f]!=-1)return dp[x][f];
  dp[x][f]=0;
  if(!f)dp[x][f]=aa[x]+dfs(x+aa[x],1);
  else dp[x][f]=aa[x]+dfs(x-aa[x],0);
  return dp[x][f];
}
int cycle(int x)
{
  if(x<=0||x>n)return 0;
  if(cy[x]!=-1)return cy[x];
  cy[x]=1;
  if(col[x]==1)return 1;
  x+=aa[x];
  if(x<=0||x>n)return 0;
  col[x]=1;
  int now=cycle(x-aa[x]);
  col[x]=2;
  return cy[x]=now;
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
    cy[1]=-1;dp[1][0]=-1;dp[1][1]=-1;
    aa[1]=i;if(cycle(1))cout<<-1<<"\n";
    else cout<<dfs(1,0)<<"\n";
  }
  return 0;
}