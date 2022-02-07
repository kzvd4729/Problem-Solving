/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-23 16:40:31                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12616
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int desc[N+2],low[N+2],ap[N+2],vis[N+2];
int n,m,tim,u,v,sub[N+2],up[N+2],cnt;
int str[N+2];
vector<int>adj[N+2],dir[N+2];
void dfs1(int node,int pre)
{
  desc[node]=low[node]=++tim;
  vis[node]=1;int child=0;
  for(int i=0;i<adj[node].size();i++)
  {
    int next=adj[node][i];
    if(!vis[next])
    {
      child++;
      dfs1(next,node);
      low[node]=min(low[node],low[next]);
      if(pre!=-1&&low[next]>=desc[node])
        ap[node]=1;
    }
    else if(next!=pre)
      low[node]=min(low[node],desc[next]);
  }
  if(pre==-1&&child>1)ap[node]=1;
}
void dfs2(int node)
{
  vis[node]=1;cnt++;
  for(auto x:adj[node])
  {
    if(vis[x])continue;
    //cout<<node<<" -- "<<x<<endl;
    dir[node].push_back(x);
    dfs2(x);
  }
}
void dfs3(int node,int tot)
{
  sub[node]=1;
  for(auto x:dir[node])
  {
    dfs3(x,tot);sub[node]+=sub[x];
  }
  up[node]=tot-sub[node];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      adj[i].clear(),dir[i].clear();
    for(int i=1;i<=m;i++)
    {
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    tim=0;
    memset(vis,0,sizeof(vis));
    memset(ap,0,sizeof(ap));
    memset(up,0,sizeof(up));
    memset(sub,0,sizeof(sub));
    memset(str,0,sizeof(str));
    for(int i=1;i<=n;i++)
    {
      if(vis[i]==0)dfs1(i,-1);
    }
    memset(vis,0,sizeof(vis));
    vector<int>rt;
    for(int i=1;i<=n;i++)
    {
      if(vis[i])continue;
      cnt=0;dfs2(i);rt.push_back(i);
      str[i]=cnt;
    }
    for(auto x:rt)
      dfs3(x,str[x]);
    /*for(int i=1;i<=n;i++)
    {
      if(up[i])cout<<up[i]<<" ";
      for(auto x:dir[i])
        cout<<sub[x]<<" ";
      cout<<endl;
    }*/
    long ans=0;
    for(int i=1;i<=n;i++)
    {
      if(!ap[i])continue;
      long sm=up[i];
      for(auto x:dir[i])
        sm+=sub[x];
      for(auto x:dir[i])
        ans+=((sm-sub[x])*1LL)*(sub[x]*1LL);
      ans+=((sm-up[i])*1LL)*(up[i]*1LL);
    }
    cout<<"Case "<<++tc<<": "<<ans<<endl;
  }
  return 0;
}