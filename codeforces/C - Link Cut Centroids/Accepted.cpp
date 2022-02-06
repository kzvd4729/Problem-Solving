/****************************************************************************************
*  @author: kzvd4729#                                        created: Apr/18/2021 22:51                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 77 ms                                           memory_used: 51700 KB                             
*  problem: https://codeforces.com/contest/1406/problem/C
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
 int n,sz[N+2],lf[N+2];
pair<int,int>dp[N+2];
bool dfs(int nd,int pr)
{
  sz[nd]=1;lf[nd]=1;
  for(auto x:ad[nd])
  {
    if(x==pr)continue;lf[nd]=0;
    if(dfs(x,nd))return true;
    sz[nd]+=sz[x];
     if(lf[x])dp[nd]={nd,x};
    else dp[nd]=dp[x];
  }
   if(sz[nd]==n/2)
  {
    if(lf[nd])assert(0);
    cout<<dp[nd].first<<" "<<dp[nd].second<<endl;
     if(pr==-1)assert(0);
    cout<<pr<<" "<<dp[nd].second<<endl;
     return true;
  }
   return false;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    cin>>n;
     for(int i=1;i<=n;i++)ad[i].clear(),sz[i]=0;
     pair<int,int>p;
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;p={u,v};
      ad[u].push_back(v);ad[v].push_back(u);
    }
     if(n%2)
    {
      cout<<p.first<<" "<<p.second<<endl;
      cout<<p.first<<" "<<p.second<<endl;
      continue;
    }
    if(dfs(1,-1)==false)
    {
      cout<<p.first<<" "<<p.second<<endl;
      cout<<p.first<<" "<<p.second<<endl;
    }
   }
  return 0;
}