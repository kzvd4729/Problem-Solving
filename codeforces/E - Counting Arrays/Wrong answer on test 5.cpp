/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/12/2019 17:32                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 1263 ms                                         memory_used: 190900 KB                            
*  problem: https://codeforces.com/contest/893/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int dp[N+2][22],pw[N+2],fac[N+2];
vector<int>ok[N+2];
void cal(void)
{
  for(int i=2;i<=N;i++)
  {
    for(int j=i;j<=N;j+=i)
    {
      ok[j].push_back(i);
    }
  }
}
int bigmod(int b,int p)
{
  int ret=1;
  while(p)
  {
    if(p&1)ret=(1LL*ret*b)%mod;
    b=(1LL*b*b)%mod;p/=2;
  }
  return ret;
}
int ncr(int n,int r)
{
  int ret=fac[n];
  ret=(1LL*ret*bigmod(fac[r],mod-2))%mod;
  ret=(1LL*ret*bigmod(fac[n-r],mod-2))%mod;
  return ret;
}
int dfs(int n,int p)
{
  if(p==0)return (n==1)?1:0;
  if(dp[n][p]!=-1)return dp[n][p];
  int now=0;
  for(auto x:ok[n])
    now=(now+dfs(n/x,p-1))%mod;
  return dp[n][p]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  pw[0]=1;for(int i=1;i<=N;i++)pw[i]=(pw[i-1]*2)%mod;
  cal();fac[0]=1;
  for(int i=1;i<=N;i++)fac[i]=(1LL*fac[i-1]*i)%mod;
  int t;cin>>t;memset(dp,-1,sizeof(dp));
  while(t--)
  {
    int n,p;cin>>n>>p;int ans=0;
    if(n==1)
    {
      cout<<pw[p-1]<<"\n";continue;
    }
    for(int i=1;i<=p;i++)
    {
      int now=dfs(n,i);if(now==0)break;
      //cout<<i<<" -> "<<now<<endl;
      now=(now*ncr(p,i))%mod;
      now=(now*pw[p-1])%mod;
      ans=(ans+now)%mod;
    }
    cout<<ans<<"\n";
  }
  return 0;
}
 