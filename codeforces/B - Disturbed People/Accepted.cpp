/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/16/2018 20:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 4900 KB                              
*  problem: https://codeforces.com/contest/1077/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4;
int n,aa[N+2],dp[N+2][5][5][5];
int dfs(int st,int a,int b,int c)
{
  if(st>n)return 0;
  if(dp[st][a][b][c]!=-1)return dp[st][a][b][c];
  int here=1e9;
  if(b==0&&c==1&&a==1)
  {
    here=min(here,1+dfs(st+1,b,c,aa[st+1]));
    here=min(here,1+dfs(st+1,b,0,aa[st+1]));
  }
  else here=min(here,dfs(st+1,b,c,aa[st+1]));
  return dp[st][a][b][c]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  memset(dp,-1,sizeof(dp));
  cout<<dfs(3,aa[1],aa[2],aa[3])<<endl;
  return 0;
}