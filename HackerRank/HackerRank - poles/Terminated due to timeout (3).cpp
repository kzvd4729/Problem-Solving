/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-04 21:39:51                      
*  solution_verdict: Terminated due to timeout               language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-poles
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=1e18;
const long N=5e3;
pair<long,long>p[N+2];
long k,n;
long dis[N+2][N+2],dp[N+2][N+2];
long dfs(long st,long kk)
{
  if(kk>k)return inf;
  if(st>n)
  {
    if(kk==k)return 0;
    else return inf;
  }
  if(dp[st][kk]!=-1)return dp[st][kk];
  long here=inf;
  for(long i=st;i<=n;i++)
    here=min(here,dis[st][i]+dfs(i+1,kk+1));
  return dp[st][kk]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  for(long i=1;i<=n;i++)
    cin>>p[i].first>>p[i].second;
  for(long i=1;i<=n;i++)
    for(long j=i+1;j<=n;j++)
      dis[i][j]+=dis[i][j-1]+(p[j].first-p[i].first)*p[j].second;
//  for(long i=1;i<=n;i++)
//  {
//    for(long j=1;j<=n;j++)
//    {
//      cout<<dis[i][j]<<" ";
//    }
//    cout<<endl;
//  }
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,0)<<endl;
  return 0;
}