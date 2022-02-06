/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/18/2020 21:33                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 43100 KB                             
*  problem: https://codeforces.com/contest/1078/problem/C
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
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e6,mod=998244353;
vector<int>adj[N+2];
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
long dp[N+2][4];
void dfs(int nd,int pr)
{
  for(int i=0;i<adj[nd].size();i++)if(adj[nd][i]==pr)adj[nd].erase(adj[nd].begin()+i);
  for(auto x:adj[nd])dfs(x,nd);
  if(adj[nd].size()==0){dp[nd][0]=1;return;}
   int n=adj[nd].size();
   int tt=1;
  for(int i=0;i<n;i++)
    tt=(tt*(dp[adj[nd][i]][0]+dp[adj[nd][i]][1]+dp[adj[nd][i]][3]))%mod;
   dp[nd][0]=tt;
   dp[nd][1]=0;
  for(int i=0;i<n;i++)
  {
    int now=(1LL*tt*big(dp[adj[nd][i]][0]+dp[adj[nd][i]][1]+dp[adj[nd][i]][3],mod-2))%mod;
    dp[nd][1]=(dp[nd][1]+now*(dp[adj[nd][i]][0]+dp[adj[nd][i]][2]))%mod;
  }
   dp[nd][2]=0;
  for(int i=0;i<n;i++)
  {
    int now=(1LL*tt*big(dp[adj[nd][i]][0]+dp[adj[nd][i]][1]+dp[adj[nd][i]][3],mod-2))%mod;
    dp[nd][2]=(dp[nd][2]+now*dp[adj[nd][i]][1])%mod;
  }
   dp[nd][3]=0;
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      int now=(1LL*tt*big(dp[adj[nd][i]][0]+dp[adj[nd][i]][1]+dp[adj[nd][i]][3],mod-2))%mod;
      now=(1LL*now*big(dp[adj[nd][j]][0]+dp[adj[nd][j]][1]+dp[adj[nd][j]][3],mod-2))%mod;
       dp[nd][3]=(dp[nd][3]+((now*dp[adj[nd][i]][1])%mod*(dp[adj[nd][j]][0]+dp[adj[nd][j]][2])))%mod;
      dp[nd][3]=(dp[nd][3]+((now*dp[adj[nd][j]][1])%mod*(dp[adj[nd][i]][0]+dp[adj[nd][i]][2])))%mod;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  int r=1;
  dfs(r,-1);
  cout<<(dp[r][0]+dp[r][1]+dp[r][3])%mod<<endl;
   return 0;
}