/****************************************************************************************
*  @author: kzvd4729#                                        created: Nov/27/2019 13:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 218 ms                                          memory_used: 11600 KB                             
*  problem: https://codeforces.com/gym/102428/problem/I
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5,mod=1e9+7;
int dp[N+2];
vector<int>adj[N+2];
int dfs(int node)
{
 if(dp[node]!=-1)return dp[node];
 dp[node]=0;if(adj[node].size()==0)dp[node]=1;
 for(auto x:adj[node])
  dp[node]=(dp[node]+dfs(x))%mod;
 return dp[node];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
   int x;cin>>x;
   while(x--)
   {
    int v;cin>>v;adj[i].push_back(v);
   }
  }
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1)<<" ";
  int cnt=0;
  for(int i=m+1;i<=n;i++)if(dp[i]==1)cnt++;
   cout<<cnt<<endl;
   return 0;
}