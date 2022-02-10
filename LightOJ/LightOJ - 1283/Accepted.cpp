/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-05 19:05:36                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 932                                        memory_used (MB): 5.8                             
*  problem: https://vjudge.net/problem/LightOJ-1283
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2,inf=1e8;
int arr[N+2],n,dp[N+2][N+2][N+2],tc;
int dfs(int st,int lt,int rt)
{
  if(st>n)return 0;
  if(dp[st][lt][rt]!=-1)return dp[st][lt][rt];
  int here=dfs(st+1,lt,rt);
  if(arr[st]>=arr[lt]&&arr[st]<=arr[rt])here=max(here,1+dfs(st+1,st,rt));
  if(arr[st]<=arr[rt]&&arr[st]>=arr[lt])here=max(here,1+dfs(st+1,lt,st));
  return dp[st][lt][rt]=here;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t;scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
    arr[0]=0,arr[n+1]=inf;
    memset(dp,-1,sizeof(dp));
    printf("Case %d: %d\n",++tc,dfs(1,0,n+1));
  }
  return 0;
}