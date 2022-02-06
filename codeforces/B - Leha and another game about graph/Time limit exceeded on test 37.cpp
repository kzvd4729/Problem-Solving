/****************************************************************************************
*  @author: kzvd4729                                         created: May/30/2021 14:47                        
*  solution_verdict: Time limit exceeded on test 37          language: GNU C++17 (64)                          
*  run_time: 3000 ms                                         memory_used: 72700 KB                             
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
const int N=1e6,inf=1e7,mod=1000000007;
 int a[N+2],vs[N+2],cnt[N+2];
vector<int>ad[N+2],id[N+2];
 int f;
void dfs(int nd)
{
  if(a[nd]==1)
  {
    a[nd]=0;f=1;return ;
  }
  else if(a[nd]==-1){f=1;return ;}
    vs[nd]=1;
  for(int i=0;i<(int)ad[nd].size();i++)
  {
    if(vs[ad[nd][i]])continue;
     cnt[id[nd][i]]^=1;dfs(ad[nd][i]);
    if(f)break ;
    cnt[id[nd][i]]^=1;
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
    ad[u].push_back(v);ad[v].push_back(u);
    id[u].push_back(i);id[v].push_back(i);
  }
   for(int i=1;i<=n;i++)
  {
    if(a[i]!=1)continue;
     a[i]=0;
    f=0;dfs(i);if(f==0)cout<<-1<<endl,exit(0);
  }
   int ans=0;
  for(int i=1;i<=m;i++)ans+=cnt[i];
  cout<<ans<<endl;
  for(int i=1;i<=m;i++)if(cnt[i])cout<<i<<" ";cout<<endl;
     return 0;
}