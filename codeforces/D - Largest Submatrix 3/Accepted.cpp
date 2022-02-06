/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 779 ms                                          memory_used: 260900 KB                            
*  problem: https://codeforces.com/contest/407/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=4e2;
int n,m,mt[N+2][N+2],dp[N+1][N+1][N+1];
bitset<N*N+2>bt[N+2];
int op(int cl,int lt,int rt,int vl)
{
  //cout<<lt<<" "<<rt<<endl;
  if(!bt[cl][vl])return rt;
  for(int i=lt;i<=rt;i++)
    if(mt[i][cl]==vl)return i-1;
  return rt;
}
void set_dp(void)
{
  for(int j=1;j<=m;j++)
  {
    for(int i=1;i<=n;i++)
    {
      bt[j][mt[i][j]]=1;
    }
  }
  for(int j=m;j>=1;j--)
  {
    dp[n][j][j]=n;
    for(int k=j+1;k<=m;k++)
    {
      if(!dp[n][j+1][k]||mt[n][j]==mt[n][k])break;
      dp[n][j][k]=n;
    }
  }
  for(int i=n-1;i>=1;i--)
  {
    if(mt[i][m]==mt[i+1][m])dp[i][m][m]=i;
    else dp[i][m][m]=op(m,i+1,dp[i+1][m][m],mt[i][m]);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      cin>>mt[i][j];
  set_dp();int ans=0;
  for(int i=n-1;i>=1;i--)
  {
    for(int j=m-1;j>=1;j--)
    {
      dp[i][j][j]=op(j,i+1,dp[i+1][j][j],mt[i][j]);
      for(int k=j+1;k<=m;k++)
      {
        if(!dp[i][j+1][k]||mt[i][j]==mt[i][k])break;
        if(!dp[i+1][j][k])
        {
          dp[i][j][k]=i;continue;
        }
        int rt=min(dp[i][j][k-1],dp[i][j+1][k]);
        rt=min(rt,dp[i+1][j][k]);
        rt=min(rt,op(j,i+1,rt,mt[i][k]));
        dp[i][j][k]=op(k,i+1,rt,mt[i][j]);
        //cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
      }
    }
  }
  for(int i=n;i>=1;i--)
  {
    for(int j=m;j>=1;j--)
    {
      for(int k=j;k<=m;k++)
      {
        if(dp[i][j][k]==0)continue;
        ans=max(ans,(k-j+1)*(dp[i][j][k]-i+1));
        //cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}