/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/17/2020 12:52                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 280 ms                                          memory_used: 30500 KB                             
*  problem: https://codeforces.com/contest/1394/problem/B
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
vector<pair<int,int> >adj[N+2],in[N+2];
int vis[10+2][10+2][10+2][10+2],k,ans,bd[10+2][10+2];
void dfs(int i,vector<pair<int,int> >v)
{
  if(i>k)
  {
    //for(auto x:v)cout<<x.second<<" ";cout<<endl;
    ans++;return;
  }
  for(int j=1;j<=i;j++)
  {
    int f=0;if(bd[i][j])continue;
    for(auto x:v)
    {
      if(vis[x.first][x.second][i][j]){f=1;break;}
    }
    if(f)continue;
    vector<pair<int,int> >cp=v;cp.push_back({i,j});
    dfs(i+1,cp);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m>>k;
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    adj[u].push_back({w,v});
  }
  for(int i=1;i<=n;i++)
  {
    sort(adj[i].begin(),adj[i].end());
    for(int j=0;j<adj[i].size();j++)
    {
      pair<int,int>p=adj[i][j];
      in[p.second].push_back({adj[i].size(),j+1});
    }
  }
  for(int i=1;i<=n;i++)
  {
    sort(in[i].begin(),in[i].end());
    for(int j=1;j<in[i].size();j++)
      if(in[i][j]==in[i][j-1])bd[in[i][j].first][in[i][j].second]=1;
    in[i].erase(unique(in[i].begin(),in[i].end()),in[i].end());
    //cout<<i<<" ";
    //for(auto x:in[i])cout<<x.first<<" ** "<<x.second<<endl;
    //cout<<endl;
    for(int j=0;j<in[i].size();j++)
    {
      for(int k=0;k<j;k++)
      {
        if(in[i][k].first==in[i][j].first)break;
        vis[in[i][k].first][in[i][k].second][in[i][j].first][in[i][j].second]=1;
      }
    }
  }
  vector<pair<int,int> >v;
  dfs(1,v);cout<<ans<<endl;
  return 0;
}