/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/24/2020 21:31                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 139 ms                                          memory_used: 35400 KB                             
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
const int N=1e6;
vector<int>adj[N+2],tree[N+2];
int vis[N+2],lev[N+2],u,v;
void dfs(int node,int par,int lv)
{
  vis[node]=1,lev[node]=lv;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(vis[x])u=node,v=x;
    else
    {
      tree[node].push_back(x);
      tree[x].push_back(node);
      dfs(x,node,lv+1);
    }
  }
}
int sub[N+2];
void dfs2(int nd,int pr)
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
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
      adj[i].clear();tree[i].clear();
      vis[i]=0;lev[i]=0;sub[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);adj[v].push_back(u);
    }
    dfs(1,-1,0);dfs2(1,-1);
     long ans=(1LL*n*(n-1))/2;
    long md=abs(lev[u]-lev[v])-1;
    long lo=min(sub[u],sub[v]);
    long up=n-md-lo;
     //cout<<u<<" "<<v<<" "<<lo<<" "<<md<<" "<<up<<endl;
     ans+=1LL*lo*up;
    ans+=1LL*md*lo;
    ans+=1LL*md*up;
    ans+=(1LL*md*(md-1))/2;
     cout<<ans<<endl;
   }
  return 0;
}