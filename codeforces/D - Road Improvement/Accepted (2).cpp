/****************************************************************************************
*  @author: kzvd4729                                         created: May/07/2020 20:36                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 26100 KB                             
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
const int N=2e5,mod=1e9+7;
vector<int>adj[N+2];int dp[N+2];
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
   for(auto &x:adj[node])if(x==par){swap(x,adj[node][0]);break;}
  int sz=adj[node].size()+2;
  vector<int>pre(sz+2),suf(sz+2);
  pre[0]=1;
  for(int i=1;i<adj[node].size();i++)
    pre[i]=(1LL*pre[i-1]*(dp[adj[node][i]]+1))%mod;
  suf[adj[node].size()]=1;
  for(int i=adj[node].size()-1;i>0;i--)
    suf[i]=(1LL*suf[i+1]*(dp[adj[node][i]]+1))%mod;
  for(int i=1;i<adj[node].size();i++)
  {
    int x=adj[node][i];
    int con=(1LL*pre[i-1]*suf[i+1])%mod;
    dds(x,node,(1LL*pr*con+1)%mod);
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
  adj[1].push_back(0);
  dfs(1,0);dds(1,0,1);
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
  return 0;
}