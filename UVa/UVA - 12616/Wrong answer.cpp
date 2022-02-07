/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-25 23:42:50                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12616
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int desc[N+2],low[N+2],ap[N+2],vis[N+2];
int n,m,tim,u,v,sub[N+2],up[N+2],cnt,par[N+2];
int str[N+2];map<pair<int,int>,int>mp;
vector<int>adj[N+2],dir[N+2];
void dfs1(int node,int pre)
{
  desc[node]=low[node]=++tim;vis[node]=1;
  for(int i=0;i<adj[node].size();i++)
  {
    int next=adj[node][i];
    if(!vis[next])
    {
      dfs1(next,node);
      low[node]=min(low[node],low[next]);
      if(low[next]>desc[node])
      {
        int uu=next,vv=node;
        if(uu>vv)swap(uu,vv);
        mp[{uu,vv}]=1;
      }
    }
    else if(next!=pre)
      low[node]=min(low[node],desc[next]);
  }
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
void dfs3(int node,int p,int tot)
{
  sub[node]=1;par[node]=p;
  for(auto x:dir[node])
  {
    dfs3(x,node,tot);sub[node]+=sub[x];
  }
  up[node]=tot-sub[node];
  if(up[node]<0)assert(0);
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
    tim=0;mp.clear();
    memset(vis,0,sizeof(vis));
    memset(ap,0,sizeof(ap));
    memset(up,0,sizeof(up));
    memset(sub,0,sizeof(sub));
    memset(str,0,sizeof(str));
    memset(low,0,sizeof(low));
    memset(desc,0,sizeof(desc));
    memset(par,0,sizeof(par));
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
    {
      dfs3(x,-1,str[x]);
      if(!str[x])assert(0);
    }
    memset(vis,0,sizeof(vis));
    long ans=0,ans2=0;
    for(int i=1;i<=n;i++)
    {
      int tt=sub[i]+up[i],br=0,vd=0;
      vector<int>ls;
      for(auto x:dir[i])
      {
        int u=i,v=x;
        if(u>v)swap(u,v);
        if(mp[{u,v}])br+=sub[x],ls.push_back(sub[x]);
        else vd+=sub[x];
      }
      int u=i,v=par[i];
      if(u>v)swap(u,v);
      if(mp[{u,v}])br+=up[i],ls.push_back(up[i]);
      else vd+=up[i];

      if(br+vd!=tt-1)assert(0);
      ls.push_back(vd);
      for(auto x:ls)
        ans2+=((x*1LL)*(tt-1-x));


      for(auto x:dir[i])
      {
        int u=i,v=x;
        if(u>v)swap(u,v);
        if(mp[{u,v}])
          ans+=(sub[x]*1LL)*((tt-sub[x]-1)*1LL);
        else ans+=(sub[x]*1LL)*(br*1LL);
      }
      u=i,v=par[i];
      if(u>v)swap(u,v);
      if(mp[{u,v}])
        ans+=(up[i]*1LL)*((tt-up[i]-1)*1LL);
      else ans+=(up[i]*1LL)*(br*1LL);
    }
    if(ans!=ans2)assert(0);
    cout<<"Case "<<++tc<<": "<<ans2<<endl;
  }
  return 0;
}