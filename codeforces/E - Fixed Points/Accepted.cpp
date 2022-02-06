/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/03/2021 15:32                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 46 ms                                           memory_used: 19900 KB                             
*  problem: https://codeforces.com/contest/1551/problem/E
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
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=2e3,inf=1e9,mod=1e9+7;
 int a[N+2],dp[N+2][N+2],n;
 int dfs(int i,int j)
{
  if(j<i)return -inf;
  if(i==0)return 0;
   if(dp[i][j]!=-1)return dp[i][j];
   int ret=dfs(i-1,j-1)+(i==a[j]);
  ret=max(ret,dfs(i,j-1));
   return dp[i][j]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
     for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=-1;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dfs(i,j);
        int ans=inf;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        //cout<<dp[i][j]<<" ";
        if(dp[i][j]>=k)ans=min(ans,j-i);
      }
      //cout<<endl;
    }
    if(ans==inf)ans=-1;
    cout<<ans<<endl;
  }
  return 0;
}