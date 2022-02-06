/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/11/2018 14:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 608 ms                                          memory_used: 1400 KB                              
*  problem: https://codeforces.com/contest/917/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
const int W=26;
int n,m,dp[N+2][N+2][W+2];
vector<pair<int,int> >adj[N+2];
bool dfs(int nd1,int nd2,int c)
{
  if(dp[nd1][nd2][c]!=-1)return dp[nd1][nd2][c];
  int hr;dp[nd1][nd2][c]=0;
  for(auto x:adj[nd1])
  {
    if(x.second>=c)
    {
      hr=1;
      for(auto y:adj[nd2])
      {
        if(y.second>=x.second)
        {
          hr&=dfs(x.first,y.first,y.second);
        }
      }
      dp[nd1][nd2][c]|=hr;
    }
  }
  return dp[nd1][nd2][c];
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v;char c;cin>>u>>v>>c;
    adj[u].push_back({v,c-'a'});
  }
  memset(dp,-1,sizeof(dp));
  for(int i=1;i<=n;i++)
  {
    string s;
    for(int j=1;j<=n;j++)
    {
      if(dfs(i,j,0))s.push_back('A');
      else s.push_back('B');
    }
    cout<<s<<endl;
  }
  return 0;
}