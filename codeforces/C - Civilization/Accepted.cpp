/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/02/2018 20:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 623 ms                                          memory_used: 24500 KB                             
*  problem: https://codeforces.com/contest/455/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int mx,vis[N+2],fr,dis[N+2];
vector<int>adj[N+2],v;
void dfs(int node,int ds,int vs)
{
  vis[node]=vs;if(ds>mx)mx=ds,fr=node;
  for(auto x:adj[node])
  {
    if(vis[x])continue;
    dfs(x,ds+1,vs);
  }
}
void farthest(int node,int par,int ds)
{
  if(ds>mx)mx=ds;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    farthest(x,node,ds+1);
  }
}
int find_root(int node)
{
  if(vis[node]==node)return node;
  return vis[node]=find_root(vis[node]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
  while(m--)
  {
    int a,b;cin>>a>>b;
    adj[a].push_back(b);adj[b].push_back(a);
  }
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    mx=-1;dfs(i,0,i);mx=-1;farthest(fr,-1,0);
    dis[i]=mx;
  }
  while(k--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int x;cin>>x;
      cout<<dis[find_root(x)]<<endl;
    }
    else
    {
      int x,y;cin>>x>>y;
      int r1=find_root(x),r2=find_root(y);
      if(r1==r2)continue;
      //cout<<r1<<" -- "<<r2<<" "<<dis[r1]<<" "<<dis[r2]<<endl;
      vis[r2]=r1;dis[r1]=max(dis[r1],(dis[r1]+1)/2+(dis[r2]+1)/2+1);
      dis[r1]=max(dis[r1],dis[r2]);
    }
  }
  return 0;
}