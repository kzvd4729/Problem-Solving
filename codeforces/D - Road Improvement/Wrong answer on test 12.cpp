/****************************************************************************************
*  @author: kzvd4729                                         created: May/07/2020 15:08                        
*  solution_verdict: Wrong answer on test 12                 language: GNU C++14                               
*  run_time: 264 ms                                          memory_used: 27200 KB                             
*  problem: https://codeforces.com/contest/543/problem/D
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
#include<unordered_map>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
vector<int>adj[N+2];int dp[N+2];
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;
    b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
void dfs(int node,int par)
{
  dp[node]=1;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);
    dp[node]=(1LL*dp[node]*(dp[x]+1))%mod;
  }
}
int ans[N+2];
void dds(int node,int par,int pr)
{
  ans[node]=(1LL*dp[node]*pr)%mod;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    int con=(1LL*dp[node]*big((dp[x]+1)%mod,mod-2))%mod;
    dds(x,node,((1LL*pr*con)+1)%mod);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=2;i<=n;i++)
  {
    int x;cin>>x;
    adj[i].push_back(x);adj[x].push_back(i);
  }
  dfs(n,-1);dds(n,-1,1);
  //for(int i=1;i<=n;i++)cout<<dp[i]<<" ";cout<<endl;
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
  return 0;
}