/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-30 15:28:26                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 180                                        memory_used (MB): 3.3                             
*  problem: https://vjudge.net/problem/LightOJ-1134
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,tc,n,m,x,xx,cnt[100005],arr[100005];
long ans;
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    scanf("%lld",&n);
    scanf("%lld",&m);
    xx=0,ans=0;
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++)
    {
      scanf("%lld",&arr[i]);
      xx=(xx+arr[i])%m;
      cnt[xx]++;
    }
    ans+=(cnt[0]*1LL);
    xx=0;
    for(int i=1;i<=n;i++)
    {
      xx=(xx+arr[i])%m;
      cnt[xx]--;
      ans+=(cnt[xx]*1LL);
    }
    printf("Case %lld: %lld\n",++tc,ans);
  }
  return 0;
}