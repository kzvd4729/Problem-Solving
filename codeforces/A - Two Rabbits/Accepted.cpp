/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/15/2020 19:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1304/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long x,y,a,b;cin>>x>>y>>a>>b;
     long lo=0,hi=1e9,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
       if(x+a*md>=y-b*md)hi=md;
      else lo=md;
    }
    long ans=-1;
    for(md=lo;md<=hi;md++)
    {
      if(x+a*md==y-b*md){ans=md;break;}
    }
    cout<<ans<<endl;
  }
    return 0;
}