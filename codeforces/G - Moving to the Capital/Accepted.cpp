/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/03/2021 18:42                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 124 ms                                          memory_used: 50100 KB                             
*  problem: https://codeforces.com/contest/1472/problem/G
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
const int N=1e6,inf=1e9,mod=1e9+7;
  vector<int>ad[N+2];
int d[N+2],dp[N+2];
 void bfs(int s,int n)
{
  for(int i=1;i<=n;i++)d[i]=inf;
  d[s]=0;queue<int>q;q.push(s);
   while((int)q.size())
  {
    int u=q.front();q.pop();
     for(auto x:ad[u])
      if(d[u]+1<d[x])d[x]=d[u]+1,q.push(x);
  }
}
 int dfs(int nd)
{
  if(dp[nd]!=-1)return dp[nd];
   dp[nd]=d[nd];
  for(auto x:ad[nd])
  {
    if(d[x]>d[nd])dp[nd]=min(dp[nd],dfs(x));
    else dp[nd]=min(dp[nd],d[x]);
  }
  return dp[nd];
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)ad[i].clear();
    for(int i=1;i<=m;i++)
    {
      int u,v;cin>>u>>v;
      ad[u].push_back(v);
    }
     for(int i=1;i<=n;i++)dp[i]=-1;
    bfs(1,n);dfs(1);
    for(int i=1;i<=n;i++)cout<<dp[i]<<" ";cout<<endl;
   }
  return 0;
}