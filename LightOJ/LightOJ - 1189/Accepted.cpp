/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-21 00:54:16                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 16                                         memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1189
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,tc;
long fac[22],n;
int main()
{
  fac[0]=1LL;
  for(int i=1;i<=20;i++)
    fac[i]=fac[i-1]*(i*1LL);
  scanf("%d",&t);
  while(t--)
  {
    scanf("%lld",&n);
    vector<int>v;
    for(int i=20;i>=0;i--)
    {
      if(n>=fac[i])
      {
        n-=fac[i];
        v.push_back(i);
      }
    }
    if(n)printf("Case %d: impossible\n",++tc);
    else
    {
      printf("Case %d: ",++tc);
      reverse(v.begin(),v.end());
      for(int i=0;i<v.size();i++)
      {
        if(i)printf("+");
        printf("%d!",v[i]);
      }
      printf("\n");
    }
  }
  return 0;
}