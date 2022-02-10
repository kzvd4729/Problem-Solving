/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-06 12:49:54                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 120                                        memory_used (MB): 1.9                             
*  problem: https://vjudge.net/problem/LightOJ-1117
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m,arr[16],t,tc,ans,pw[17];
long lcm[(1<<15)+2];
int main()
{
  pw[0]=1;
  for(int i=1;i<17;i++)
    pw[i]=pw[i-1]*2;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
      scanf("%d",&arr[i]);
    ans=0;

    lcm[0]=1;
    for(int i=1;i<(1<<m);i++)
    {
      int tmp=31-__builtin_clz(i);
      int x=(pw[tmp]-1)&i;

      lcm[i]=(lcm[x]*arr[tmp])/__gcd(lcm[x],arr[tmp]*1LL);

      if(__builtin_popcount(i)%2==0)
        ans-=(n/lcm[i]);
      else ans+=(n/lcm[i]);
    }
    printf("Case %d: %d\n",++tc,n-ans);
  }
  return 0;
}