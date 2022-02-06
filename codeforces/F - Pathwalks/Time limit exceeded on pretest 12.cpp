/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/08/2018 00:20                        
*  solution_verdict: Time limit exceeded on pretest 12       language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 7600 KB                              
*  problem: https://codeforces.com/contest/960/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int dp[100005],n,m,u,v,w,print;
vector<pair<int,pair<int,int> > >adj[100005];
int dfs(int node,int weight,int i)
{
  //if(dp[node]!=-1)return dp[node];
  int xx=0;
  for(auto x:adj[node])
  {
    if(x.second.first>i&&x.second.second>weight)
    {
      xx=max(xx,1+dfs(x.first,x.second.second,x.second.first));
    }
  }
  return xx;
  //return dp[node]=max(xx,dp[node]);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   memset(dp,-1,sizeof(dp));
   cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    cin>>u>>v>>w;
    adj[u].push_back({v,{i,w}});
  }
   for(int i=1;i<=n;i++)print=max(print,dfs(i,-1,-1));
 //  cout<<endl<<endl;
//  for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
//  cout<<endl;
//
//  for(int i=1;i<=n;i++)print=max(print,dp[i]);
//  cout<<print<<endl;
cout<<print<<endl;
  return 0;
}