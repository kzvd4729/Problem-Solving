/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/11/2020 22:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 436 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1461/problem/E
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
#include<sstream> 
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e6;
long l,r,k,t,x,y;
bool solve1()
{
  long mv=0;
  if(k+y<=r)k+=y;
   if(k-x>=l)mv++,k-=x;else return mv>=t;
   long fl=(k-l)/(x-y);
  mv+=fl;
  return mv>=t;
}
bool solve2()
{
  long mv=0;
  for(long i=0;i<=N+N;i++)
  {
    if(k+y<=r)k+=y;
    long lo=1,hi=(k-l)/x,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(k-md*x+y<=r)hi=md;
      else lo=md;
    }
    long f=0;
    for(md=lo;md<=hi;md++)
    {
      if(k-md*x+y<=r){f=1;break;}
    }
    if(f==0)
    {
      mv+=(k-l)/x;
      return mv>=t;
    }
    mv+=md;k-=md*x;
    if(mv>=t)return true;
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>k>>l>>r>>t>>x>>y;
   if(y<x)
  {
    if(solve1())cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  else
  {
    if(solve2())cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
   return 0;
}