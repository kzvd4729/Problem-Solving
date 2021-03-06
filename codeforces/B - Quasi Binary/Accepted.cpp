/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/15/2019 23:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 50800 KB                             
*  problem: https://codeforces.com/contest/538/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int dp[N+2];
vector<int>v;
void dfs(int nm)
{
  if(nm>N)return ;
  v.push_back(nm);
  dfs(nm*10);dfs(nm*10+1);
}
int dfs2(int nm)
{
  if(nm<0)return 1e9;
  if(nm==0)return dp[nm]=0;
  if(dp[nm]!=-1)return dp[nm];
  int now=1e9;
  for(auto x:v)
    now=min(now,1+dfs2(nm-x));
  return dp[nm]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  dfs(1);memset(dp,-1,sizeof(dp));
  int n;cin>>n;int ans=dfs2(n);
   cout<<ans<<endl;
  while(n)
  {
    for(auto x:v)
    {
      if(n-x<0)continue;
      if(dp[n-x]==dp[n]-1)
      {
        cout<<x<<" ";
        n-=x;break;
      }
    }
  }
  cout<<endl;
  return 0;
}