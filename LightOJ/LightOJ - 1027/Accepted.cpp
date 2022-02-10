/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-06 15:06:45                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1027
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,tc,n,arr[102],e,sum;
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    int f=0;
    for(int i=1;i<=n;i++)
    {
      scanf("%d",&arr[i]);
      if(arr[i]>0)f=1;
    }
    if(!f)
      printf("Case %d: inf\n",++tc);
    else
    {
      e=0;
      sum=0;
      for(int i=1;i<=n;i++)
      {
        if(arr[i]<0)e++;
        sum+=abs(arr[i]);
      }
      e=n-e;
      int gcd=__gcd(e,sum);
      e/=gcd;
      sum/=gcd;
      printf("Case %d: %d/%d\n",++tc,sum,e);

    }
  }
  return 0;
}