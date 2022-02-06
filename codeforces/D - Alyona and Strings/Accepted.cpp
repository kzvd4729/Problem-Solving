/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/01/2019 15:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 51200 KB                             
*  problem: https://codeforces.com/contest/682/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int dp[N+2][N+2],dp2[N+2][N+2][12];
string a,b;
int dfs(int i,int j,int k)
{
  if(i==a.size()||j==b.size())return 0;
  if(dp2[i][j][k]!=-1)return dp2[i][j][k];
  int mx=0;
  mx=max(mx,dfs(i+1,j,k));
  mx=max(mx,dfs(i,j+1,k));
  int mt=dp[i][j];
  if(mt&&k)
    mx=max(mx,mt+dfs(i+mt,j+mt,k-1));
  return dp2[i][j][k]=mx;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;cin>>a>>b;
   for(int i=a.size()-1;i>=0;i--)
  {
    for(int j=b.size()-1;j>=0;j--)
    {
      if(a[i]!=b[j])dp[i][j]=0;
      else dp[i][j]=1+dp[i+1][j+1];
    }
  }
  memset(dp2,-1,sizeof(dp2));
  cout<<dfs(0,0,k)<<endl;
  return 0;
}