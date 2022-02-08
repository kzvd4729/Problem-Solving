/****************************************************************************************
*  @author: kzvd4729                                         created: 15-07-2018 14:43:08                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.04 sec                                        memory_used: 15.8M                                
*  problem: https://www.codechef.com/JULY18A/problems/GEARS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;
const int inf=1e8;
int n,m,arr[N+2],f;
int ty,u,v,x,dis[N+2],vis[N+2];
vector<int>adj[N+2];
map<pair<int,int>,int>mp;
void dfs(int node,int par)
{
  if(vis[node])
  {
    f=1;
    return ;
  }
  vis[node]=1;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(f)return ;
    dfs(x,node);
  }
}
int bfs(int node,int tar)
{
  queue<int>q;
  for(int i=1;i<=n;i++)
    dis[i]=inf;
  q.push(node);
  dis[node]=0;
  while(q.size())
  {
    int node=q.front();
    q.pop();
    for(auto x:adj[node])
    {
      if(dis[x]==inf)
      {
        dis[x]=dis[node]+1;
        q.push(x);
      }
    }
  }
  return dis[tar];
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  while(m--)
  {
    cin>>ty;
    if(ty==1)
    {
      cin>>u>>x;
      arr[u]=x;
    }
    else if(ty==2)
    {
      cin>>u>>v;
      if(u>v)swap(u,v);
      if(mp[{u,v}])continue;
      mp[{u,v}]=1;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    else
    {
      cin>>u>>v>>x;
      f=0;
      memset(vis,0,sizeof(vis));
      dfs(u,-1);
      int dss=inf;
      if(f==0)dss=bfs(u,v);
      if(f)cout<<0<<endl;
      else if(dss==inf)cout<<0<<endl;
      else
      {
        long tmp=arr[u]*1LL*x;
        long gcd=__gcd(tmp,arr[v]*1LL);
        if(dss%2==0)
          cout<<tmp/gcd<<"/"<<arr[v]/gcd<<endl;
        else cout<<"-"<<tmp/gcd<<"/"<<arr[v]/gcd<<endl;
      }
    }
  }
  return 0;
}