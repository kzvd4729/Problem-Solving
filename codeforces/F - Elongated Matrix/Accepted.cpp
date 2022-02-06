/****************************************************************************************
*  @author: * kzvd4729                                       created: Jan/09/2019 22:34                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 545 ms                                          memory_used: 66500 KB                             
*  problem: https://codeforces.com/contest/1102/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int mat[20][10004],mnm[20][20],n,m,lst[20][20],fr;
int dp[(1<<16)+2][16][16];
int dfs(int msk,int ls)
{
  if(__builtin_popcount(msk)==n)
  {
    return lst[ls+1][fr+1];
  }
  if(dp[msk][fr][ls]!=-1)return dp[msk][fr][ls];
  int ret=0;
  for(int i=1;i<=n;i++)
  {
    if(msk&(1<<(i-1)))continue;
    ret=max(ret,min(mnm[ls+1][i],dfs(msk|(1<<(i-1)),i-1)));
  }
  return dp[msk][fr][ls]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>mat[i][j];
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int ii=1;ii<=n;ii++)
    {
      int mn=1e9;
      for(int j=1;j<=m;j++)
      {
        mn=min(mn,abs(mat[i][j]-mat[ii][j]));
      }
      mnm[i][ii]=mn;
      //cout<<i<<" "<<ii<<" "<<mn<<endl;
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int ii=1;ii<=n;ii++)
    {
      int mn=1e9;
      for(int j=1;j<m;j++)
      {
        mn=min(mn,abs(mat[i][j]-mat[ii][j+1]));
      }
      lst[i][ii]=mn;
    }
  }
  memset(dp,-1,sizeof(dp));
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    fr=i-1;
    ans=max(ans,dfs(1<<(i-1),i-1));
    //cout<<ans<<endl;
  }
  cout<<ans<<endl;
  return 0;
}