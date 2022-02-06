/****************************************************************************************
*  @author: kzvd4729                                         created: May/28/2020 21:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 514 ms                                          memory_used: 4100 KB                              
*  problem: https://codeforces.com/contest/1359/problem/C
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    double h,c,t;cin>>h>>c>>t;
    long lo=1,hi=1e12,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      double now=(md*1.0*h)/((md+md-1)*1.0)+((md-1)*1.0*c)/((md+md-1)*1.0);
      if(now>t)lo=md;else hi=md;
    }
    double df=1e9;long ans;
    for(md=lo;md<=hi;md++)
    {
      double now=(md*1.0*h)/((md+md-1)*1.0)+((md-1)*1.0*c)/((md+md-1)*1.0);
      if(abs(now-t)<df)df=abs(now-t),ans=md+md-1;
    }
    //cout<<df<<endl;
    double av=((h+c)*1.0)/2.0;
    if(abs(av-t)<df)ans=2;cout<<ans<<endl;
  }
  return 0;
}