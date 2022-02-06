/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/17/2018 19:53                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 152900 KB                            
*  problem: https://codeforces.com/contest/165/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=4e6;
int fr[N+N+2],aa[N+N+2];
int dp[22][(1<<20)+2];
int dfs(int st,int msk)
{
  if(st<0)
  {
    if(fr[msk])return msk;
    return 0;
  }
  if(dp[st][msk]!=-1)return dp[st][msk];
  int here=0;
  if(msk&(1<<st))
  {
    here=max(here,dfs(st-1,msk));
    here=max(here,dfs(st-1,msk^(1<<st)));
  }
  else
  {
    here=max(here,dfs(st-1,msk));
  }
  return dp[st][msk]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];fr[aa[i]]=1;
  }
  memset(dp,-1,sizeof(dp));
  for(int i=1;i<=n;i++)
  {
    int tmp=0;
    for(int j=0;j<22;j++)
      if(!(aa[i]&(1<<j)))tmp|=(1<<j);
    int xx=dfs(21,tmp);
    if(!xx)xx=-1;
    cout<<xx<<" ";
  }
  cout<<endl;
  return 0;
}