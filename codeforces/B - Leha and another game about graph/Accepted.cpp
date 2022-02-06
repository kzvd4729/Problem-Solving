/****************************************************************************************
*  @author: kzvd4729                                         created: May/30/2021 15:09                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 467 ms                                          memory_used: 129700 KB                            
*  problem: https://codeforces.com/contest/840/problem/B
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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1000000007;

vector<pair<int,int> >ad[N+2],tree[N+2];//rooted tree

int vis[N+2],lev[N+2];
void dfs(int node,int par,int lv)
{
  vis[node]=1,lev[node]=lv;
  for(auto x:ad[node])
  {
    if(x.first==par)continue;
    if(vis[x.first])
    {
    }
    else
    {
      tree[node].push_back(x);
      tree[x.first].push_back({node,x.second});

      //cout<<node<<" "<<x.first<<" "<<x.second<<endl;
      dfs(x.first,node,lv+1);
    }
  }
}

int a[N+2],cnt[N+2];

void dds(int nd,int pr,int id)
{
  for(auto x:tree[nd])
  {
    if(x.first==pr)continue;

    dds(x.first,nd,x.second);
  }
  if(pr==-1)return ;

  if(a[nd]==1)
  {
    cnt[id]^=1;a[nd]=0;
    if(a[pr]!=-1)a[pr]^=1;
  }
}

int f;int vs[N+2];
void dfs(int nd)
{
  if(a[nd]==1)
  {
    a[nd]=0;f=1;return ;
  }
  else if(a[nd]==-1){f=1;return ;}
  
  vs[nd]=1;
  for(int i=0;i<(int)tree[nd].size();i++)
  {
    if(vs[tree[nd][i].first])continue;

    cnt[tree[nd][i].second]^=1;dfs(tree[nd][i].first);
    if(f)break ;
    cnt[tree[nd][i].second]^=1;
  }
  vs[nd]=0;
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>a[i];

  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    ad[u].push_back({v,i});ad[v].push_back({u,i});
  }

  dfs(1,-1,0);dds(1,-1,0);
  int ans=0;
  
  f=1;if(a[1]==1){f=0;a[1]=0;dfs(1);}

  if(f==0)cout<<-1<<endl,exit(0);

  for(int i=1;i<=m;i++)ans+=cnt[i];
  cout<<ans<<endl;
  for(int i=1;i<=m;i++)if(cnt[i])cout<<i<<" ";cout<<endl;

  
  return 0;
}