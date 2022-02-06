/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/17/2020 20:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 327 ms                                          memory_used: 700 KB                               
*  problem: https://codeforces.com/contest/981/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4,mod=1e9+7;
int vis[N+2],dp[N+2];
void add(int x)
{
  for(int i=N;i>=x;i--)
  {
    dp[i]=(dp[i]+dp[i-x]);
    if(dp[i])
    {
      vis[i]=1;if(dp[i]>=mod)dp[i]-=mod;
    }
  }
  //for(int i=1;i<=20;i++)cout<<dp[i]<<" ";cout<<endl;
}
void erase(int x)
{
  for(int i=x;i<=N;i++)
  {
    dp[i]=(dp[i]-dp[i-x]);
    if(dp[i]<0)dp[i]+=mod;
  }
  //for(int i=1;i<=20;i++)cout<<dp[i]<<" ";cout<<endl;
}
vector<int>ad[N+2],rm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  dp[0]=1;
  int n,q;cin>>n>>q;
  for(int i=1;i<=q;i++)
  {
    int l,r,x;cin>>l>>r>>x;
    ad[l].push_back(x);rm[r].push_back(x); 
  }
  for(int i=1;i<=n;i++)
  {
    for(auto x:ad[i])add(x);
    for(auto x:rm[i])erase(x);
  }
  int cnt=0;
  for(int i=1;i<=n;i++)if(vis[i])cnt++;
  cout<<cnt<<endl;
  for(int i=1;i<=n;i++)if(vis[i])cout<<i<<" ";cout<<endl;
  return 0;
}