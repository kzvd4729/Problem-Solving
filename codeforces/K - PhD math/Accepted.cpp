/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/18/2019 21:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 4508 ms                                         memory_used: 817900 KB                            
*  problem: https://codeforces.com/gym/100814/problem/K
****************************************************************************************/
#include<bits/stdc++.h>
#define long unsigned long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],dp[N+2][200+2],n,p;
inline int dfs(int i,int m)
{
  if(i>n)return 0;
  if(dp[i][m]!=-1)return dp[i][m];
  int ret=0,nx=(m*10+aa[i])%p;
  if(nx==0)ret++;
   return dp[i][m]=ret+dfs(i+1,nx);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long a,b;cin>>a>>b;cin>>n>>p;
    for(int i=1;i<=n;i++)
    {
      a*=10;aa[i]=a/b;
      a%=b;
    }
    //memset(dp,-1,sizeof(dp));
    for(int i=0;i<=n+1;i++)
      for(int j=0;j<=p+1;j++)dp[i][j]=-1;
    long ans=0;
    for(int i=1;i<=n;i++)
      ans+=dfs(i,0);
    cout<<ans<<"\n";
  }
  return 0;
}