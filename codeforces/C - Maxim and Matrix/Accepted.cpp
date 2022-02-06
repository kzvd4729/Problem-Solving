/****************************************************************************************
*  @author: kzvd4729                                         created: May/10/2019 18:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/261/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,t,dp[60][60][3];
long dfs(long i,long j,long ck)
{
  if(j<0)return 0;
  if(i<0)
  {
    if(!j)return 1;
    return 0;
  }
  if(dp[i][j][ck]!=-1)return dp[i][j][ck];
  long now=0;
  if(!ck)
    now+=dfs(i-1,j,0)+dfs(i-1,j-1,0);
  else
  {
    bool dg=(n&(1LL<<i));
    if(!dg)now+=dfs(i-1,j,1);
    else now+=dfs(i-1,j,0)+dfs(i-1,j-1,1);
  }
  return dp[i][j][ck]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>t;n++;int ad=0;if(t==1)ad--;
  long p=0;
  while(t%2==0)t/=2,p++;
  if(t!=1)cout<<0<<endl,exit(0);
    memset(dp,-1,sizeof(dp));
  cout<<dfs(50,p+1,1)+ad<<endl;
   return 0;
}