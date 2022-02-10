/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-30 15:24:31                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1134
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,tc,n,m,x,xx,cnt[100005],arr[100005];
long ans;
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    scanf("%d",&m);
    xx=0,ans=0;
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++)
    {
      scanf("%d",&arr[i]);
      xx+=arr[i];
      cnt[xx%m]++;
    }
    ans+=(cnt[0]*1LL);
    xx=0;
    for(int i=1;i<=n;i++)
    {
      xx+=arr[i];
      cnt[xx%m]--;
      ans+=(cnt[xx%m]*1LL);
    }
    printf("Case %d: %lld",++tc,ans);
  }
  return 0;
}