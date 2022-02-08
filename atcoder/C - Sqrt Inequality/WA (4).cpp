/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-14 18:14:09                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_c
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
double sqt(double d)
{
  double lo=0,hi=d,md;int lopp=1000;
  while(lopp--)
  {
    md=(lo+hi)/2.0;
    if(md*md>d)hi=md;
    else lo=md;
  }
  return md;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  double a,b,c;cin>>a>>b>>c;
   if(sqt(a)+sqt(b)<sqt(c))cout<<"Yes\n";
  else cout<<"No\n";
   return 0;
}