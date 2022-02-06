/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/05/2020 16:49                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 35300 KB                             
*  problem: https://codeforces.com/contest/1453/problem/F
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
const int N=3e3;
int n,a[N+2],dp[N+2][N+2],ps[N+2],vs[N+2];
void dfs(int nd)
{
  vs[nd]=1;
  for(int i=nd+1;i<=n;i++)
  {
    if(vs[i])continue;
    if(dp[nd][i])dfs(i);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
     for(int i=1;i<=n;i++)
    {
      vs[i]=0,ps[i]=0;
      for(int j=1;j<=n;j++)dp[i][j]=0;
    }
    ps[n]=1;
    for(int i=n-1;i>=1;i--)
    {
      for(int j=i+1;j<=i+a[i];j++)
      {
        if(ps[j])dp[i][j]=1,ps[i]=1;
      }
    }
    dfs(1);int nd=1,ans=0;
    while(nd<n)
    {
      int now;
      for(int i=nd+1;i<=n;i++)
      {
        if(dp[nd][i]&&vs[i])now=i;
      }
      for(int i=nd+1;i<now;i++)
      {
        if(dp[nd][i]&&vs[i])ans+=(i+a[i]>=now);
      }
      nd=now;
    }
    cout<<ans<<endl;
  }
  return 0;
}