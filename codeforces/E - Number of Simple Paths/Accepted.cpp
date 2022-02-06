/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/25/2020 13:36                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 374 ms                                          memory_used: 86500 KB                             
*  problem: https://codeforces.com/contest/1454/problem/E
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
#include<sstream> 
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const long N=1e6;
vector<long>adj[N+2],tree[N+2];
long vis[N+2],lev[N+2],u,v,f;
void dfs(long node,long par,long lv)
{
  vis[node]=1,lev[node]=lv;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(vis[x])
    {
      if(f==0)u=node,v=x,f=1;
    }
    else
    {
      tree[node].push_back(x);
      tree[x].push_back(node);
      dfs(x,node,lv+1);
    }
  }
}
long sub[N+2],par[N+2];
void dfs2(long nd,long pr)
{
  sub[nd]=1;par[nd]=pr;
  //cout<<nd<<" --> "<<pr<<endl;
  for(auto x:tree[nd])
  {
    if(x==pr)continue;
    dfs2(x,nd);sub[nd]+=sub[x];
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long n;cin>>n;
    for(long i=1;i<=n;i++)
    {
      adj[i].clear();tree[i].clear();
      vis[i]=0;lev[i]=0;sub[i]=0;
    }
    for(long i=1;i<=n;i++)
    {
      long u,v;cin>>u>>v;
      adj[u].push_back(v);adj[v].push_back(u);
    }
    u=-1,v=-1;
    f=0;dfs(1,-1,0);dfs2(1,-1);
    //cout<<u<<" "<<v<<endl;
    assert(u>0&&v>0&&u<=n&&v<=n);
     //for(int i=1;i<=n;i++)cout<<sub[i]<<" ";cout<<endl;
     if(lev[u]<lev[v])swap(u,v);
    long ans=1LL*n*(n-1);//cout<<ans<<endl;
    long lo=min(sub[u],sub[v]);
    long md=0;
    while(true)
    {
      if(par[u]==v)break;long cnt=1;
      for(auto x:tree[par[u]])
      {
        if(x==u||lev[x]<lev[par[u]])continue;
        //cout<<x<<" ** "<<sub[x]<<endl;
        cnt+=sub[x];
      }
      ans-=(1LL*cnt*(cnt-1))/2;
      md+=sub[par[u]]-sub[u];u=par[u];
    }
    //cout<<md<<endl;
    long up=n-md-lo;
     //cout<<lo<<" "<<md<<" "<<up<<endl;
     assert(md>=0&&md<=n&&lo>=1&&up>=1);
    assert(lo+md+up==n);
     //cout<<u<<" "<<v<<" "<<lo<<" "<<md<<" "<<up<<endl;
    ans-=(1LL*lo*(lo-1))/2;
    ans-=(1LL*up*(up-1))/2;
        cout<<ans<<endl;
   }
  return 0;
}