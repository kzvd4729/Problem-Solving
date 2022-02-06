/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/23/2018 17:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 2215 ms                                         memory_used: 1300 KB                              
*  problem: https://codeforces.com/contest/294/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=5e3;
const long inf=1e18;
long len[N+2],sz[N+2],flg[N+2];
vector<pair<long,long> >adj[N+2];
struct edge
{
  long u,v,w;
};
vector<edge>ed;
void dfs(long node,long par)
{
  sz[node]=1;flg[node]=1;
  for(auto x:adj[node])
  {
    if(x.first==par)continue;
    dfs(x.first,node);sz[node]+=sz[x.first];
    len[node]+=len[x.first]+sz[x.first]*x.second;
  }
}
void dds(long node,long par,long ds,long siz)
{
  len[node]+=ds;
  for(auto x:adj[node])
  {
    if(x.first==par)continue;
    dds(x.first,node,len[node]-len[x.first]-sz[x.first]*x.second+(siz-sz[x.first])*x.second,siz);
  }
}
void dbs(long node,long par,long ds,long ln,long siz,long wt)
{
  len[node]+=ln+siz*(ds+wt);
  for(auto x:adj[node])
  {
    if(x.first==par)continue;
    dbs(x.first,node,ds+x.second,ln,siz,wt);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  for(long i=1;i<n;i++)
  {
    long u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
    ed.push_back({u,v,w});
  }
  long ans=inf;
  for(auto x:ed)
  {
    for(long i=0;i<adj[x.u].size();i++)
    {
      if(adj[x.u][i]==make_pair(x.v,x.w))
      {
        adj[x.u].erase(adj[x.u].begin()+i);
        break;
      }
    }
    for(long i=0;i<adj[x.v].size();i++)
    {
      if(adj[x.v][i]==make_pair(x.u,x.w))
      {
        adj[x.v].erase(adj[x.v].begin()+i);
        break;
      }
    }
    memset(len,0,sizeof(len));
    memset(flg,0,sizeof(flg));
    dfs(x.u,-1);dds(x.u,-1,0,sz[x.u]);
    long mx=inf,n1,n2;
    for(long i=1;i<=n;i++)
    {
      if(flg[i]==0)continue;
      if(len[i]<=mx)
      {
        mx=len[i];n1=i;
      }
    }
    mx=inf;memset(flg,0,sizeof(flg));
    dfs(x.v,-1);dds(x.v,-1,0,sz[x.v]);
    for(long i=1;i<=n;i++)
    {
      if(flg[i]==0)continue;
      if(len[i]<=mx)
      {
        mx=len[i];n2=i;
      }
    }
    long oth=len[n1];
    dbs(n1,-1,0,len[n2],sz[x.v],x.w);
    dbs(n2,-1,0,oth,sz[x.u],x.w);
    long now=0;
    for(long i=1;i<=n;i++)
      now+=len[i];
    ans=min(now,ans);
    adj[x.u].push_back({x.v,x.w});
    adj[x.v].push_back({x.u,x.w});
  }
  cout<<ans/2<<endl;
  return 0;
}