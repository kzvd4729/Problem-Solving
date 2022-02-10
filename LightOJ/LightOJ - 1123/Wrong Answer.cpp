/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-18 01:31:43                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1123
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=1e12;
long vis[202],tr,parent,child,costt,mst,cnt,ret,t,tc,n,m,u,v,w;
vector<pair<long,long> >adj[202];
void dfs(long node,long uu,long vv,long cst)
{
  if(node==tr)
  {
    parent=uu;
    child=vv;
    costt=cst;
    ret=1;
    return ;
  }
  vis[node]=1;
  for(long i=0;i<adj[node].size();i++)
  {
    if(ret)return ;
    if(vis[adj[node][i].first])continue;
    if(adj[node][i].second>cst)
      dfs(adj[node][i].first,node,adj[node][i].first,adj[node][i].second);
    else dfs(adj[node][i].first,uu,vv,cst);
  }
}
void _dfs(long node)
{
  vis[node]=1;
  cnt++;
  for(long i=0;i<adj[node].size();i++)
  {
    if(vis[adj[node][i].first])continue;
    mst+=adj[node][i].second;
    _dfs(adj[node][i].first);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    for(long i=0;i<=200;i++)adj[i].clear();
    cin>>n>>m;
    printf("Case %lld:\n",++tc);
    while(m--)
    {
      cin>>u>>v>>w;
      memset(vis,0,sizeof(vis));
      ret=0;
      tr=v;
      costt=inf;
      dfs(u,0,0,0);
      if(costt>w)
      {
        for(long i=0;i<adj[parent].size();i++)
        {
          if(adj[parent][i].first==child)
          {
            adj[parent].erase(adj[parent].begin()+i);
            break;
          }
        }
        for(long i=0;i<adj[child].size();i++)
        {
          if(adj[child][i].first==parent)
          {
            adj[child].erase(adj[child].begin()+i);
            break;
          }
        }
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
      }
//      cout<<endl<<endl;
//      for(int i=1;i<=n;i++)
//      {
//        cout<<i<<"   ";
//        for(auto x:adj[i])
//          cout<<x.first<<" "<<x.second<<"   ";
//        cout<<endl;
//      }

      memset(vis,0,sizeof(vis));
      mst=0;
      cnt=0;
      _dfs(1);
      if(cnt==n)
        printf("%lld\n",mst);
      else printf("-1\n");

    }
  }
  return 0;
}