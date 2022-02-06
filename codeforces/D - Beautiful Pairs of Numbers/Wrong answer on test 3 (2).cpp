/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/02/2019 15:12                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 1544 ms                                         memory_used: 180800 KB                            
*  problem: https://codeforces.com/contest/403/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3,mod=1e9+7;
int dp[N+2][N+2][40+2],fac[N+2];
int dfs(int sm,int k,int l)
{
  if(sm<0)return 0;if(!l)return !(bool)sm;if(k<0)return 0;
   if(dp[sm][k][l]!=-1)return dp[sm][k][l];
  int now=0;
  now=dfs(sm,k-1,l)+dfs(sm-k,k-1,l-1);
  return dp[sm][k][l]=now%mod;
}
int ncr[2000+2][2000+2];
void NCR(int n)
{
  for(int i=1;i<=n;i++)
    ncr[i][0]=1;
  ncr[1][1]=1;
  for(int i=2;i<=n;i++)
    for(int j=1;j<=n;j++)
      ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  fac[0]=1;for(int i=1;i<=N;i++)fac[i]=(1LL*fac[i-1]*i)%mod;
  memset(dp,-1,sizeof(dp));NCR(N+N);
   int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    if(k>40)
    {
      cout<<0<<"\n";continue;
    }
    int ans=0;
    for(int i=0;i<=n;i++)
    {
      int way=dfs(i,i,k);
      way=(1LL*way*fac[k])%mod;
      //cout<<i<<" --> "<<way<<endl;
      //cout<<i<<" <--> "<<n-i<<endl;
      //if(n-i-k<0)continue;
      int rm=n-i-k;if(rm<0)continue;
      //cout<<"***"<<rm<<endl;
      way=(1LL*way*ncr[rm+k][k])%mod;
      ans=(ans+way)%mod;
    }
    cout<<ans<<"\n";
  }
  return 0;
}