/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-16 21:42:24                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 666                                        memory_used (MB): 6.2                             
*  problem: https://vjudge.net/problem/LightOJ-1194
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int m,n,c[15+2][15+2];long dp[(1<<16)+2];
vector<int>po[N+2];
long dfs(int msk)
{
  if(msk==(1<<m)-1)return 0;
  if(dp[msk]!=-1)return dp[msk];
  long now=1e18;
  for(int i=1;i<=m;i++)
  {
    if(msk&(1<<(i-1)))continue;
    int cst=0;
    for(int j=1;j<=m;j++)
    {
      if(!(msk&(1<<(j-1))))
        cst+=c[i][j];
    }
    now=min(now,cst+dfs(msk|(1<<(i-1))));
  }
  return dp[msk]=now;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=1;i<=m;i++)po[i].clear();
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      po[x].push_back(i);
    }
    memset(c,0,sizeof(c));
    for(int i=1;i<=m;i++)
    {
      for(int j=1;j<=m;j++)
      {
        for(auto x:po[i])
          c[i][j]+=upper_bound(po[j].begin(),po[j].end(),x)-po[j].begin();
      }
    }
    for(int i=1;i<=m;i++)c[i][i]=0;
    memset(dp,-1,sizeof(dp));
    cout<<"Case "<<++tc<<": "<<dfs(0)<<"\n";
  }
  return 0;
}
/*
3
4 2
1 2 1 2
6 4
2 1 4 3 1 2
8 6
1 3 2 5 5 4 5 2
*/