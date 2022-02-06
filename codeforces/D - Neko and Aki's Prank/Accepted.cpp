/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/24/2019 22:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 94300 KB                             
*  problem: https://codeforces.com/contest/1152/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e3;
const long mod=1e9+7;
long n,mrk[N+2][N+2];
long dp[N+2][N+2][2];
long dfs(long i,long bl)
{
  if(bl<0)return 0;
  if(i>n)
  {
    if(bl)return mrk[i][bl]=0;
    return mrk[i][bl]=1;
  }
  if(mrk[i][bl]!=-1)return mrk[i][bl];
  long now=0;
  now=dfs(i+1,bl+1)|dfs(i+1,bl-1);
  return mrk[i][bl]=now;
}
long dfs2(long i,long bl,long f)
{
  if(dp[i][bl][f]!=-1)return dp[i][bl][f];
  long now=0;
  if(bl<N&&mrk[i+1][bl+1]==1&&bl>0&&mrk[i+1][bl-1]==1)
  {
    now=dfs2(i+1,bl+1,0)+dfs2(i+1,bl-1,0);
    if(!f)
    {
      now=max(now,1+dfs2(i+1,bl+1,1)+dfs2(i+1,bl-1,0));
      now=max(now,dfs2(i+1,bl+1,0)+1+dfs2(i+1,bl-1,1));
    }
  }
  else if(bl<N&&mrk[i+1][bl+1]==1)
  {
    now=dfs2(i+1,bl+1,0);
    if(!f)
    {
      now=max(now,1+dfs2(i+1,bl+1,1));
    }
  }
  else if(bl>0&&mrk[i+1][bl-1]==1)
  {
    now=dfs2(i+1,bl-1,0);
    if(!f)
    {
      now=max(now,1+dfs2(i+1,bl-1,1));
    }
  }
  return dp[i][bl][f]=now%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;n+=n;memset(mrk,-1,sizeof(mrk));
  dfs(1,0);memset(dp,-1,sizeof(dp));
  cout<<dfs2(1,0,0)%mod<<endl;
  return 0;
}