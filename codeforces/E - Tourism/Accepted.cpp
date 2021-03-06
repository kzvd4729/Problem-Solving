/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/19/2019 01:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 686 ms                                          memory_used: 40500 KB                             
*  problem: https://codeforces.com/contest/1220/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
 struct dfsSpanningTree
{
  vector<int>adj[N+2],tree[N+2];//rooted tree
  vector<pair<int,int> >br;
  vector<int>bkadj[N+2];//for back edge
   int vis[N+2],lev[N+2];
  dfsSpanningTree()
  {
    br.clear();
    for(int i=0;i<=N;i++)
    {
      adj[i].clear(),tree[i].clear();
      bkadj[i].clear();
      vis[i]=0,lev[i]=0;
    }
  }
  void dfs(int node,int par,int lv)
  {
    vis[node]=1,lev[node]=lv;
    for(auto x:adj[node])
    {
      if(x==par)continue;
      if(vis[x])
      {
        bkadj[node].push_back(x);
        bkadj[x].push_back(node);
      }
      else
      {
        tree[node].push_back(x);
        tree[x].push_back(node);
        dfs(x,node,lv+1);
      }
    }
  }
  int bridge(int node,int par)
  {
    int mn=1e9;
    for(auto x:bkadj[node])
      mn=min(mn,lev[x]);
    for(auto x:tree[node])
    {
      if(x==par)continue;
      mn=min(mn,bridge(x,node));
    }
    if(mn>=lev[node]&&par!=-1)
      br.push_back({par,node});
    return mn;
  }
}tree;
int ww[N+2],vis[N+2],cnt[N+2],num[N+2];
long cost[N+2],ans;
map<pair<int,int>,int>mp;
vector<int>adj[N+2];
void dfs(int node,int nm)
{
  cnt[nm]++,num[node]=nm,cost[nm]+=1LL*ww[node];
  vis[node]=1;
  for(auto x:tree.adj[node])
  {
    if(vis[x])continue;
    if(mp.count({node,x})||mp.count({x,node}))continue;
    dfs(x,nm);
  }
}
int trav(int node,int par)
{
  bool f=(cnt[node]>1);
  for(auto x:adj[node])
  {
    if(x==par)continue;
    f|=trav(x,node);
  }
  ans+=cost[node]*f;
  if(f)cost[node]=0;
  return f;
}
long again(int node,int par)
{
  long mx=0;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    mx=max(mx,again(x,node));
  }
  return mx+cost[node];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>ww[i];
  vector<pair<int,int> >ed;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    tree.adj[u].push_back(v);
    tree.adj[v].push_back(u);
    ed.push_back({u,v});
  }
  int sr;cin>>sr;
  tree.dfs(sr,-1,0);tree.bridge(sr,-1);
  for(auto x:tree.br)mp[x]=1;
   dfs(sr,sr);
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    dfs(i,i);
  }
  mp.clear();
  for(auto x:ed)
  {
    int u=num[x.first],v=num[x.second];
    if(u==v)continue;
    if(mp.count({u,v})||mp.count({v,u}))continue;
    mp[{u,v}]=1;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  trav(sr,-1);cout<<ans+again(sr,-1)<<endl;
  return 0;
}