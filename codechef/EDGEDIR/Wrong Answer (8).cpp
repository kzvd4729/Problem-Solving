/****************************************************************************************
*  @author: kzvd4729                                         created: 10-12-2018 18:28:36                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.54 sec                                        memory_used: 44.5M                                
*  problem: https://www.codechef.com/DEC18A/problems/EDGEDIR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int cnt[N+2],ans[N+2],par[N+2],vis[N+2],f;
set<int>adj[N+2];vector<int>vc[N+2];
map<pair<int,int>,int>dir;
void dfs(int node,int pre)
{
  if(par[node]&&pre!=-1)
  {
    f=1;return ;
  }
  vis[node]=1;
  for(auto x:vc[node])
  {
    if(vis[x])continue;
    dfs(x,node);
    if(f)
    {
      int u=node,v=x;
      int ff=dir[{u,v}];
      par[u]^=1;par[v]^=1;
      if(ff)ans[ff]^=1;
      else ans[dir[{v,u}]]^=1;
      //vis[node]=0;
      return ;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;dir.clear();
    for(int i=1;i<=n;i++)adj[i].clear(),cnt[i]=0,vc[i].clear();
    for(int i=1;i<=m;i++)
    {
      int u,v;cin>>u>>v;
      adj[u].insert(v);cnt[u]++;
      adj[v].insert(u);cnt[v]++;
      vc[u].push_back(v);vc[v].push_back(u);
      dir[{u,v}]=i;
    }
    if(m%2)
    {
      cout<<-1<<endl;continue;
    }
    set<pair<int,int> >pq;
    for(int i=1;i<=n;i++)
      pq.insert({cnt[i],i});
    memset(par,0,sizeof(par));
    vector<pair<int,int> >ed;
    for(int i=1;i<=m;i++)
    {
      pair<int,int>p=*pq.begin();pq.erase(p);
      int u=p.second,v=*adj[p.second].begin();
      adj[u].erase(v);adj[v].erase(u);
      pq.erase({cnt[v],v});
      cnt[u]--;cnt[v]--;
      if(par[u])
      {
        par[u]^=1;ed.push_back({v,u});
      }
      else 
      {
        par[v]^=1;ed.push_back({u,v});
      }
      if(cnt[u])pq.insert({cnt[u],u});
      if(cnt[v])pq.insert({cnt[v],v});
    }
    int as=0;
    for(int i=1;i<=n;i++)
      if(par[i])as++;
    if(as%2)assert(0);
    memset(ans,0,sizeof(ans));
    for(auto x:ed)
    {
      if(dir[x])ans[dir[x]]=0;
      else ans[dir[{x.second,x.first}]]=1;
    }
    memset(vis,0,sizeof(vis));
    // for(int i=1;i<=n;i++)
    // {
    //   if(par[i])
    //   {
    //     f=0;
    //     memset(vis,0,sizeof(vis));
    //     dfs(i,-1);
    //     if(!f)assert(0);
    //   }
    // }
    // for(int i=1;i<=n;i++)
    //   if(par[i])assert(0);
    for(int i=1;i<=m;i++)
      cout<<ans[i]<<" ";
    cout<<endl;
  }
  return 0;
}