/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/04/2020 21:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 530 ms                                          memory_used: 31500 KB                             
*  problem: https://codeforces.com/contest/1453/problem/E
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
vector<int>ad[N+2];
int f,md,dp[N+2];
void dfs(int nd,int pr)
{
  int mn=N+2,mx=-1,smx=-2;
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    dfs(x,nd);
     if(dp[x]>mx)
    {
      smx=mx;mx=dp[x];
    }
    else smx=max(smx,dp[x]);
     mn=min(mn,dp[x]);
  }
  if(mx==-1){dp[nd]=0;return ;}
  if(mx<=md-2)dp[nd]=mn+1;
  else dp[nd]=mx+1;
   if(dp[nd]>md||smx>md-2)f=1;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)ad[i].clear();
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      ad[u].push_back(v);ad[v].push_back(u);
    }
    //md=1;dfs(1,-1);exit(0);
    int lo=1,hi=n+2;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      f=0;for(int i=1;i<=n;i++)dp[i]=0;
      dfs(1,-1);
      if(f)lo=md;else hi=md;
    }
    for(md=lo;md<=hi;md++)
    {
      f=0;for(int i=1;i<=n;i++)dp[i]=0;
      dfs(1,-1);if(f==0)break;
    }
    cout<<md<<endl;
  }
  return 0;
}