/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-01 16:47:36                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 276                                        memory_used (MB): 3.3                             
*  problem: https://vjudge.net/problem/LightOJ-1421
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const int inf=1e9;
int t,tc,arr[N+2],tmp[N+2],inc[N+2],n;
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++)
      tmp[i]=inf;
    tmp[0]=-inf;
    for(int i=1;i<=n;i++)
    {
      int id=lower_bound(tmp,tmp+1+n,arr[i])-tmp;
      inc[i]=id;
      tmp[id]=arr[i];
    }
    for(int i=1;i<=n;i++)
      tmp[i]=inf;
    tmp[0]=-inf;
    int ans=0;
    for(int i=n;i>=1;i--)
    {
      int id=lower_bound(tmp,tmp+1+n,arr[i])-tmp;
      ans=max(ans,min(inc[i],id)*2-1);
      tmp[id]=arr[i];
    }
    printf("Case %d: %d\n",++tc,ans);
  }
  return 0;
}