/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/24/2020 22:37                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 139 ms                                          memory_used: 47100 KB                             
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
long sub[N+2];
void dfs2(long nd,long pr)
{
  sub[nd]=1;
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
    assert(u>0&&v>0&&u<=n&&v<=n);
     long ans=(1LL*n*(n-1))/2;
    long md=abs(lev[u]-lev[v])-1;
    long lo=min(sub[u],sub[v]);
    long up=n-md-lo;
     assert(md>=0&&md<=n&&lo>=1&&up>=1);
    assert(lo+md+up==n);
     //cout<<u<<" "<<v<<" "<<lo<<" "<<md<<" "<<up<<endl;
    ans+=1LL*lo*up;
    ans+=1LL*md*lo;
    ans+=1LL*md*up;
    ans+=((1LL*md*(md-1))/2);
     cout<<ans<<endl;
   }
  return 0;
}