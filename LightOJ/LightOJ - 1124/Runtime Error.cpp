/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-16 18:30:48                      
*  solution_verdict: Runtime Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1124
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const int mod=1e9+7;
int lo[N+2],hi[N+2],dp[11][N+1],qm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;scanf("%d",&t);
  while(t--)
  {
    int n,a;scanf("%d%d",&n,&a);
    for(int i=1;i<=n;i++)
      scanf("%d%d",&lo[i],&hi[i]);
    memset(dp,0,sizeof(dp));
    for(int i=lo[1];i<=hi[1];i++)
      dp[1][i]=1;
    qm[0]=0;
    for(int i=1;i<=a;i++)
      qm[i]=qm[i-1]+dp[1][i];
    for(int i=2;i<=n;i++)
    {
      for(int j=lo[i];j<=a;j++)
      {
        int lt=j-lo[i];
        int rt=max(0,j-hi[i]);
        if(!rt)dp[i][j]=qm[lt];
        else dp[i][j]=qm[lt]-qm[rt-1];
        if(dp[i][j]<0)dp[i][j]+=mod;
        if(dp[i][j]>=mod)dp[i][j]-=mod;
      }
      for(int j=1;j<=a;j++)
      {
        qm[j]=qm[j-1]+dp[i][j];
        if(qm[j]>=mod)qm[j]-=mod;
      }
    }
    printf("Case %d: %d\n",++tc,dp[n][a]);
  }
  return 0;
}