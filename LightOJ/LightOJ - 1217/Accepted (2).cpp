/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-10 22:08:23                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 4                                          memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1217
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,tc,arr[1004],dp1[1004],dp2[1004],n;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%d",&arr[i]);

    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
    dp1[1]=arr[1];
    for(int i=2;i<n;i++)
      dp1[i]=max(dp1[i-1],dp1[i-2]+arr[i]);
    for(int i=2;i<=n;i++)
      dp2[i]=max(dp2[i-1],dp2[i-2]+arr[i]);
    printf("Case %d: %d\n",++tc,max(dp1[n-1],dp2[n]));
  }
  return 0;
}