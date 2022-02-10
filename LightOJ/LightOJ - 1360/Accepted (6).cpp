/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-18 13:54:35                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 204                                        memory_used (MB): 17.3                            
*  problem: https://vjudge.net/problem/LightOJ-1360
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,tc,n,ans,dp[500005];
struct data
{
  long st,ed,cs;
}arr[500004];
bool cmp(data A,data B)
{
  return A.ed<B.ed;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  scanf("%lld",&t);
  while(t--)
  {
    memset(dp,0,sizeof(dp));
    scanf("%lld",&n);
    for(long i=1;i<=n;i++)
    {
      scanf("%lld",&arr[i].st);
      scanf("%lld",&arr[i].ed);
      scanf("%lld",&arr[i].cs);
      arr[i].ed=arr[i].st+arr[i].ed-1;
    }
    sort(arr+1,arr+n+1,cmp);
    ans=0;
    for(long i=1;i<=n;i++)
    {
      for(long j=arr[i-1].ed;j<=arr[i].ed;j++)
        dp[j]=max(dp[j],dp[j-1]);
      dp[arr[i].ed]=max(dp[arr[i].ed],dp[arr[i].st-1]+arr[i].cs);
      ans=max(ans,dp[arr[i].ed]);
    }
    printf("Case %lld: %lld\n",++tc,ans);
  }
  return 0;
}