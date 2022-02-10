/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-16 14:58:45                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1265                                       memory_used (MB): 0.6                             
*  problem: https://vjudge.net/problem/URAL-1526
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int bad[10+2],dp[100+2][(1<<10)+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int p,t,n,m;cin>>p>>t>>n>>m;t/=2;

  for(int i=1;i<=m;i++)
  {
    int a,b;cin>>a>>b;a--,b--;
    bad[b]|=(1<<a);
  }
  //for(int i=0;i<(1<<n);i++)dp[0][i]=1;
  for(int i=1;i<=t;i++)
  {
    for(int msk=0;msk<(1<<n);msk++)
    {
      for(int j=0;j<n;j++)
      {
        if(bad[j]&msk)continue;
        if(i==1)dp[i][msk]++;
        else
        {
          dp[i][msk]=(dp[i][msk]+dp[i-1][msk])%p;
          dp[i][msk]=(dp[i][msk]+dp[i-1][msk|(1<<j)])%p;
          for(int k=1;k<i-1;k++)
          {
            dp[i][msk]=(dp[i][msk]+(1LL*dp[k][msk|(1<<j)]*dp[i-k-1][msk])%p)%p;
          }
        }
      }
      //cout<<dp[i][msk]<<" ";
    }
    //cout<<endl;
  }
  cout<<dp[t][0]%p<<endl;
  return 0;
}