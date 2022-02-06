/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/27/2018 19:24                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 452 ms                                          memory_used: 46900 KB                             
*  problem: https://codeforces.com/contest/954/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e9;
int vis[1003],u,v,dis[1003][1003],n,m,sr,ds;
vector<int>adj[1002];
map<pair<int,int>,int>mp;
void bfs(int sr)
{
  memset(vis,0,sizeof(vis));
  queue<int>q;
  q.push(sr);
  vis[sr]=1;
  dis[sr][sr]=0;
  while(q.size())
  {
    u=q.front();
    q.pop();
    for(auto x:adj[u])
    {
      if(vis[x])continue;
      dis[sr][x]=dis[sr][u]+1;
      q.push(x);
      vis[x]=1;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   for(int i=1;i<=1000;i++)
  {
    for(int j=1;j<=1000;j++)
    {
      dis[i][j]=inf;
    }
  }
  cin>>n>>m>>sr>>ds;
  for(int i=1;i<=m;i++)
  {
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    mp[{u,v}]=1;
    mp[{v,u}]=1;
  }
  for(int i=1;i<=n;i++)bfs(i);
  int mn=dis[sr][ds];
  int cnt=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(i==j||mp[{i,j}])continue;
      if(dis[sr][i]+dis[j][ds]+1>=mn&&dis[sr][j]+dis[i][ds]+1>=mn)cnt++;
      mp[{i,j}]=1;
      mp[{j,i}]=1;
    }
  }
  cout<<cnt<<endl;
  return 0;
}