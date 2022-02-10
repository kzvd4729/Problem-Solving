/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-14 19:38:42                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 590                                        memory_used (MB): 2.7                             
*  problem: https://vjudge.net/problem/LightOJ-1193
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=100000007;
long n,m,k,qm[15002],qmq[15002];
long dp[2][15002];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t,tc=0;cin>>t;
  while(t--)
  {
    cin>>n>>m>>k;memset(dp,0,sizeof(dp));
    dp[(n+1)%2][0]=1;
    for(long i=0;i<=k;i++)qm[i]=1;
    qmq[0]=qm[0];
    for(long j=1;j<=k;j++)
      qmq[j]=(qmq[j-1]+qm[j])%mod;
    for(long i=n;i>=1;i--)
    {
      int id=i%2;memset(dp[id],0,sizeof(dp[id]));
      for(long j=1;j<=k;j++)
      {
        dp[id][j]=qmq[j-1];
        long sb=j-m-1;if(sb<0)continue;
        dp[id][j]=(dp[id][j]-(qmq[sb]+qm[sb]*m)%mod+mod)%mod;
      }
      qm[0]=dp[id][0];
      for(long j=1;j<=k;j++)
        qm[j]=(qm[j-1]+dp[id][j])%mod;
      qmq[0]=qm[0];
      for(long j=1;j<=k;j++)
        qmq[j]=(qmq[j-1]+qm[j])%mod;
    }
    cout<<"Case "<<++tc<<": "<<dp[1][k]%mod<<"\n";
  }
  return 0;
}