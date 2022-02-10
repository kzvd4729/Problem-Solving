/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-11 15:49:56                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 242                                        memory_used (MB): 3.8                             
*  problem: https://vjudge.net/problem/LightOJ-1084
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const int inf=1e9;
int n,k,aa[N+2],nex[N+2],dp[N+2];
int dfs(int i)
{
  if(i>n)return 0;
  if(dp[i]!=-1)return dp[i];
  if(nex[i]-i+1<3)return inf;
  int now=inf;
  for(int j=nex[i];j>=max(nex[i]-5,i+2);j--)
    now=min(now,1+dfs(j+1));
  return dp[i]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>aa[i];
    sort(aa+1,aa+n+1);
    for(int i=1;i<=n;i++)
    {
      int lo=i,hi=n,md;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(aa[md]-aa[i]>k+k)hi=md;
        else lo=md;
      }
      for(md=hi;md>=lo;md--)
        if(aa[md]-aa[i]<=k+k)break;
      nex[i]=md;
    }
    memset(dp,-1,sizeof(dp));
    int ans=dfs(1);if(ans==inf)ans=-1;
    cout<<"Case "<<++tc<<": "<<ans<<"\n";
  }
  return 0;
}