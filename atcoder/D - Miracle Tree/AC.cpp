/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-04-27 23:35:06                      
*  solution_verdict: AC                                      language: C++ (GCC 9.2.1)                         
*  run_time: 172 ms                                          memory_used: 51128 KB                             
*  problem: https://atcoder.jp/contests/arc117/tasks/arc117_d
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
 int dp[N+2],ds[N+2];
 vector<int>ad[N+2];
 void dfs0(int nd,int pr,int d)
{
  ds[nd]=d;
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    dfs0(x,nd,d+1);
  }
}
 void dfs(int nd,int pr)
{
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    dfs(x,nd);
     dp[nd]=max(dp[nd],dp[x]+1);
  }
}
 int ans[N+2],tim;
void dds(int nd,int pr)
{
  int big=-1;ans[nd]=++tim;
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    if(dp[x]+1==dp[nd] && big==-1)
    {
      big=x;continue;
    }
    dds(x,nd);tim++;
  }
  if(big!=-1)
  {
    dds(big,nd);tim++;
  }
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    ad[u].push_back(v);
    ad[v].push_back(u);
  }
   dfs0(1,-1,0);
   int rt=1;int mn=-inf;
  for(int i=1;i<=n;i++)
  {
    if(ds[i]>mn)mn=ds[i],rt=i;
  }
   dfs(rt,-1);
  dds(rt,-1);
   for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}