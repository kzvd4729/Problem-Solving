/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/29/2021 20:54                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 358 ms                                          memory_used: 196200 KB                            
*  problem: https://codeforces.com/contest/1519/problem/D
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
const int N=5000,inf=1e9,mod=1e9+7;
 long a[N+2],b[N+2];
long dp[N+2][N+2];
 long dfs(int i,int j)
{
  if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
   if(i==j)return dp[i][j]=1LL*a[i]*b[i];
  return dp[i][j]=1LL*a[i]*b[j]+1LL*a[j]*b[i]+dfs(i+1,j-1);
}
 long pre[N+2],suf[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
   for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n;i++)cin>>b[i];
   memset(dp,-1,sizeof dp);
   for(int i=1;i<=n;i++)pre[i]=pre[i-1]+1LL*a[i]*b[i];
   for(int i=n;i>=1;i--)suf[i]=suf[i+1]+1LL*a[i]*b[i];
   long ans=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=i;j<=n;j++)
    {
      ans=max(ans,pre[i-1]+suf[j+1]+dfs(i,j));
    }
  }
  cout<<ans<<endl;
       return 0;
}