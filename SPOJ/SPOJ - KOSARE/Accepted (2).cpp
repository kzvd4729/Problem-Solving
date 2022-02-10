/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-16 13:44:10                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 440                                        memory_used (MB): 8.1                             
*  problem: https://vjudge.net/problem/SPOJ-KOSARE
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=(1<<20),mod=1e9+7;
int dp[N+2],pw[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    int x,msk=0;cin>>x;
    while(x--)
    {
      int j;cin>>j;msk|=(1<<(j-1));
    }
    dp[msk]++;
  }
  for(int i=0;i<m;i++)
  {
    for(int msk=0;msk<(1<<m);msk++)
    {
      if(msk&(1<<i))dp[msk]+=dp[msk^(1<<i)];
    }
  }
  pw[0]=1;
  for(int i=1;i<=n;i++)pw[i]=(pw[i-1]+pw[i-1])%mod;
  int ans=0;
  for(int i=0;i<(1<<m);i++)
  {
    if((m-__builtin_popcount(i))%2==0)ans=(ans+pw[dp[i]])%mod;
    else ans=(ans-pw[dp[i]])%mod;
  }
  cout<<(ans+mod)%mod<<endl;
  return 0;
}