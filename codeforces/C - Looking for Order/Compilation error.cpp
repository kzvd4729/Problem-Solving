/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/16/2018 20:33                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/8/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=24;
int n,mat[N+2][N+2],dp[(1<<N)+2];
pair<int,int>pp[N+2];
int dis(int i,int j)
{
  int ret=0;
  ret+=(pp[i].first-pp[j].first)*(pp[i].first-pp[j].first);
  ret+=(pp[i].second-pp[j].second)*(pp[i].second-pp[j].second);
  return ret;
}
int dfs(int msk)
{
  if(__builtin_popcount(msk)==n)return 0;
  if(dp[msk]!=-1)return dp[msk];
  int here=2e9;
  for(int i=0;i<n;i++)
  {
    if(msk&(1<<i))continue;
    for(int j=0;j<n;j++)
    {
      if(msk&(1<<j))continue;
      here=min(here,mat[i][j]+dfs((msk|(1<<i))|(1<<j)));
    }
  }
  return dp[msk]=here;
}
int main()
{
   dont complie
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>pp[25].first>>pp[25].second>>n;
  for(int i=0;i<n;i++)
    cin>>pp[i].first>>pp[i].second;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      mat[i][j]=dis(25,i)+dis(i,j)+dis(j,25);
    }
  }
  memset(dp,-1,sizeof(dp));
  int ans=dfs(0);cout<<ans<<endl;
  int msk=0;vector<int>pr;
  for(int i=0;i<n;i++)
  {
    if(msk&(1<<i))continue;
    for(int j=0;j<n;j++)
    {
      if(msk&(1<<j))continue;
      int tmp=(msk|(1<<i))|(1<<j);
      if(dp[tmp]==ans-mat[i][j])
      {
        msk=tmp;
        if(i==j)
        {
          pr.push_back(0);
          pr.push_back(i);
        }
        else
        {
          pr.push_back(0);
          pr.push_back(i);
          pr.push_back(j);
        }
      }
      here=min(here,mat[i][j]+dfs((msk|(1<<i))|(1<<j)));
    }
  }
  return 0;
}