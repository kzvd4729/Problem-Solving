/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/07/2020 22:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 4100 KB                              
*  problem: https://codeforces.com/contest/463/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3,inf=1e9;
int a[5+2][N+2],p[5+2][N+2],dp[N+2][N+2],n,k;
int dfs(int ls,int cr)
{
  if(cr>n)return 0;
  if(dp[ls][cr]!=-1)return dp[ls][cr];
  int now=dfs(ls,cr+1);
   int f=0;
  for(int i=2;i<=k;i++)
    if(p[i][a[1][cr]]<p[i][a[1][ls]])f=1;
  if(!f)now=max(now,1+dfs(cr,cr+1));
   return dp[ls][cr]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<=k;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cin>>a[i][j];p[i][a[i][j]]=j;
    }
  }
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0,1)<<endl;
    return 0;
}