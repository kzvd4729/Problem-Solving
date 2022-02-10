/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-18 14:01:13                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 132                                        memory_used (MB): 2.8                             
*  problem: https://vjudge.net/problem/LightOJ-1360
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,tc,n,ans,dp[200001];
struct data
{
  int st,ed,cs;
}arr[30001];
bool cmp(data A,data B)
{
  return A.ed<B.ed;
}
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    memset(dp,0,sizeof(dp));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
      scanf("%d%d%d",&arr[i].st,&arr[i].ed,&arr[i].cs);
      arr[i].ed=arr[i].st+arr[i].ed-1;
    }
    sort(arr+1,arr+n+1,cmp);
    ans=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=arr[i-1].ed;j<=arr[i].ed;j++)
        dp[j]=max(dp[j],dp[j-1]);
      dp[arr[i].ed]=max(dp[arr[i].ed],dp[arr[i].st-1]+arr[i].cs);
      ans=max(ans,dp[arr[i].ed]);
    }
    printf("Case %d: %d\n",++tc,ans);
  }
  return 0;
}