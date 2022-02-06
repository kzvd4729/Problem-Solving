/****************************************************************************************
*  @author: * kzvd4729                                       created: May/14/2020 21:52                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 764 ms                                          memory_used: 3800 KB                              
*  problem: https://codeforces.com/contest/1353/problem/F
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
const int N=1e2;
long aa[N+2][N+2],dp[N+2][N+2],n,m;
long dfs(int i,int j,long x)
{
  if(i>n||j>m||x>aa[i][j])return 1e18;
  long now=aa[i][j]-x;if(i==n&&j==m)return now;
  if(dp[i][j]!=-1)return dp[i][j];
  return dp[i][j]=now+min(dfs(i+1,j,x+1),dfs(i,j+1,x+1));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)cin>>aa[i][j];
    }
    long ans=1e18;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        for(int a=1;a<=n;a++)for(int b=1;b<=m;b++)dp[a][b]=-1;
        ans=min(ans,dfs(1,1,aa[i][j]-(i+j-2)));
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}