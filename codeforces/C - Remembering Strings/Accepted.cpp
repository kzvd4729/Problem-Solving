/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/15/2020 22:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 4300 KB                              
*  problem: https://codeforces.com/contest/543/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=(1<<20),inf=1e9;
int c[20+2][20+2],sn[20+2],dp[N+2];
int id[20+2][20+2],cs[20+2][20+2],n,m;
string s[20+2];
int dfs(int i,int msk)
{
  if(i==n)return 0;
  if(dp[msk]!=-1)return dp[msk];
   if(msk&(1<<i))return dp[msk]=dfs(i+1,msk);
  int ret=sn[i]+dfs(i+1,msk|(1<<i));
  for(int j=0;j<m;j++)
    ret=min(ret,cs[i][j]+dfs(i+1,msk|id[i][j]));
  return dp[msk]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=0;i<n;i++)cin>>s[i];
   for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)cin>>c[i][j];
  }
  for(int i=0;i<n;i++)sn[i]=inf;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      sn[i]=min(sn[i],c[i][j]);
       int mx=0;
      for(int k=0;k<n;k++)
      {
        if(s[i][j]!=s[k][j])continue;
        id[i][j]|=(1<<k);cs[i][j]+=c[k][j];mx=max(mx,c[k][j]);
      }
      cs[i][j]-=mx;
    }
  }
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0,0)<<endl;
  return 0;
}