/****************************************************************************************
*  @author: kzvd4729                                         created: 08-07-2019 18:32:49                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 1.22 sec                                        memory_used: 19.8M                                
*  problem: https://www.codechef.com/JULY19A/problems/CIRMERGE
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=400;
const long inf=1e18;
long dp[N+N+2][N+N+2],aa[N+N+2],qm[N+N+2];
long dfs(int lo,int hi)
{
  if(hi==lo)return 0;
  if(dp[lo][hi]!=-1)return dp[lo][hi];
  long mn=1e18;
  for(int i=lo;i<hi;i++)
    mn=min(mn,dfs(lo,i)+dfs(i+1,hi));
  return dp[lo][hi]=mn+qm[hi]-qm[lo-1];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)
      cin>>aa[i],aa[n+i]=aa[i];
    for(int i=1;i<=n+n;i++)
      qm[i]=qm[i-1]+aa[i];
    long ans=1e18;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
      ans=min(ans,dfs(i,i+n-1));
    cout<<ans<<endl;
  }
  return 0;
}