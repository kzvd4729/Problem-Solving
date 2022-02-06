/****************************************************************************************
*  @author: kzvd4729                                         created: May/10/2019 17:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 122 ms                                          memory_used: 1100 KB                              
*  problem: https://codeforces.com/contest/261/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=50;
int id,ms,aa[N+2],p,n;
long long dp[N+2][N+2][N+2];
long double fac[N+2];
long long dfs(int i,int j,int s)
{
  if(j<0)return 0;if(s>p)return 0;
  if(i>n)
  {
    if(s+aa[id]>p&&!j)return 1;
    return 0;
  }
  if(dp[i][j][s]!=-1)return dp[i][j][s];
  if(i==id)return dp[i][j][s]=dfs(i+1,j,s);
  return dp[i][j][s]=dfs(i+1,j,s)+dfs(i+1,j-1,s+aa[i]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  fac[0]=1;
  for(int i=1;i<=N;i++)
    fac[i]=fac[i-1]*i;
  cin>>n;int sum=0;
  for(int i=1;i<=n;i++)
    cin>>aa[i],sum+=aa[i];
  cin>>p;
  if(sum<=p)cout<<n<<endl,exit(0);
  long double ans=0;
  for(int i=1;i<=n;i++)
  {
    id=i;memset(dp,-1,sizeof(dp));
    for(int j=1;j<n;j++)
    {
      long long x=dfs(1,j,0);
      //cout<<i<<" -- "<<j<<" -- "<<x<<" "<<(fac[j]*fac[n-1-j]*x*j)<<endl;
      ans+=(fac[j]*fac[n-1-j]*x*j)/fac[n];
    }
  }
  cout<<setprecision(10)<<fixed<<ans<<endl;
  return 0;
}