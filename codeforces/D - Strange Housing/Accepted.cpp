/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/11/2021 17:09                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 280 ms                                          memory_used: 40000 KB                             
*  problem: https://codeforces.com/contest/1470/problem/D
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
int vs[N+2],cl[N+2],sz,cnt;
void dfs(int nd)
{
  if(vs[nd])return ;vs[nd]=1;sz++;
  int f=0;
  for(auto x:ad[nd])if(cl[x])f=1;
   if(f==0)cl[nd]=1,cnt++;
  for(auto x:ad[nd])dfs(x);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)ad[i].clear(),vs[i]=0,cl[i]=0;sz=0;cnt=0;
    for(int i=1;i<=m;i++)
    {
      int u,v;cin>>u>>v;
      ad[u].push_back(v);ad[v].push_back(u);
    }
    dfs(1);if(sz<n){cout<<"NO\n";continue;}
    cout<<"YES\n";cout<<cnt<<'\n';
    for(int i=1;i<=n;i++)
      if(cl[i])cout<<i<<" ";
    cout<<'\n';
  } 
  return 0;
}