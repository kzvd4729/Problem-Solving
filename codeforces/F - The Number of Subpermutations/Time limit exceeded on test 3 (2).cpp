/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/09/2019 19:07                        
*  solution_verdict: Time limit exceeded on test 3           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 35200 KB                             
*  problem: https://codeforces.com/contest/1175/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1000001011;
const int N=1e6,bs=307;
int aa[N+2],dp[N+2],lst[N+2];
long pw[N+2],qm[N+2],hs[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;pw[0]=1;
  for(int i=1;i<=n;i++)pw[i]=(pw[i-1]*bs)%mod;
  for(int i=1;i<=n;i++)qm[i]=(qm[i-1]+pw[i])%mod;
  for(int i=1;i<=n;i++)cin>>aa[i];
  dp[n+1]=n+1;
  for(int i=n;i>=1;i--)
  {
    dp[i]=dp[i+1];
    if(lst[aa[i]])dp[i]=min(dp[i],lst[aa[i]]);
    lst[aa[i]]=i;
  }
  for(int i=1;i<=n;i++)
    hs[i]=(hs[i-1]+pw[aa[i]])%mod;
  int ans=0;dp[0]=1;
  for(int i=1;i<=n;i++)
  {
    int ln=min(n-i+1,aa[i-1]-1);
    ln=min(ln,dp[i-1]-i);
    for(int j=i+aa[i]-1;j<i+ln;j++)
      if(((hs[j]-hs[i-1]+mod)%mod)==qm[j-i+1])ans++;
    for(int j=max(dp[i-1],i+aa[i]-1);j<dp[i];j++)
      if(((hs[j]-hs[i-1]+mod)%mod)==qm[j-i+1])ans++;
  }
  cout<<ans<<endl;
  return 0;
}