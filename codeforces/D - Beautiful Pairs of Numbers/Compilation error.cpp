/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/02/2019 03:51                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
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
  //if(dp[sm][k][l]!=-1)return dp[sm][k][l];
 int now=0;
 now=dfs(sm,k-1,l)+dfs(sm-k,k-1,l-1);
 return dp[sm][k][l]=now%mod;
}
int big(int b,int p)
{
 int r=1;
 while(p)
 {
  if(p&1)r=(1LL*r*b)%mod;
  b=(1LL*b*b)%mod;p/=2;
 }
 return r;
}
int ncr(int n,int r)
{
 if(n<0)return 0;
 int ret=(1LL*fac[n]*big(fac[r],mod-2))%mod;
 return (1LL*ret*big(fac[n-r],mod-2))%mod;
}
int main()
{
 dont compile
  ios_base::sync_with_stdio(0);cin.tie(0);
  fac[0]=1;for(int i=1;i<=N;i++)fac[i]=(1LL*fac[i-1]*i)%mod;
  memset(dp,-1,sizeof(dp));
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
    cout<<i<<" --> "<<way<<endl;
    way=(1LL*way*ncr(n-i-k+1,k))%mod;
    ans=(ans+way)%mod;
   }
   cout<<ans<<"\n";
  }
  return 0;
}