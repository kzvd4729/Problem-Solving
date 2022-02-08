/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-07 18:42:17                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 2 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/arc094/tasks/arc094_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long q,a,b,lo,hi,md,x,sc,ans,y,ex;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>q;
  while(q--)
  {
    ex=0;
    cin>>a>>b;
    sc=a*b;
    lo=1;
    hi=sc-1;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      long x=(sc-1)/md;
      if(x<md)hi=md;
      else lo=md;
    }
    for(long i=lo;i<=hi;i++)
    {
      x=i;
      y=(sc-1)/x;
      if(x==y)ex=1;
      if(y<x)break;
      ans=i;
    }
    if(a<=ans||b<=ans)ex++;
    ans=ans*2;
    ans-=ex;
    cout<<ans<<endl;
  }
  return 0;
}