/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-20 18:06:41                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/agc024/tasks/agc024_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=2e18;
long a,b,c,k,ta,tb,tc;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>a>>b>>c>>k;
   if(a==b&&b==c)cout<<0<<endl,exit(0);
   for(long i=1;i<=k;i++)
  {
    ta=b+c;
    tb=a+c;
    tc=a+b;
    a=ta;
    b=tb;
    c=tc;
    if(a>inf||b>inf||c>inf)
    {
      cout<<"Unfair"<<endl;
      return 0;
    }
  }
  long ans=a-b;
  if(ans>(inf/2))
  {
    cout<<"Unfair"<<endl;
      return 0;
  }
  cout<<a-b<<endl;
   return 0;
}