/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-04 23:16:42                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 6490                                       memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-poles
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=1e16;
const int N=5e3;
int k,n,first[N+1],second[N+1];
long dis[N+1][N+1],dp[N+1][N+1];
inline long dfs(int st,int kk)
{
  if(st>n)
  {
    if(kk==k)return 0;
    else return inf;
  }
  if(kk>k||n-st+kk+1<k)return inf;
  if(dp[st][kk]!=-1)return dp[st][kk];
  long here=inf;
  for(int i=st;i<=n;i++)
  {
    if(dis[st][i]>=here)break;
    here=min(here,dis[st][i]+dfs(i+1,kk+1));
  }
  return dp[st][kk]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>k;int i,j;
  for(i=1;i<=n;i++)
    cin>>first[i]>>second[i];
  for(i=1;i<=n;i++)
    for(j=i+1;j<=n;j++)
      dis[i][j]+=dis[i][j-1]+((first[j]-first[i])*1LL)*second[j];
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,0)<<endl;
  return 0;
}