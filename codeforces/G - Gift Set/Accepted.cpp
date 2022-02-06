/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/10/2021 21:11                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1538/problem/G
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
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long N=1e6,inf=1e9,mod=1e9+7;
  int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long t;cin>>t;
  while(t--)
  {
    long x,y,a,b;cin>>x>>y>>a>>b;
     if(x>y)swap(x,y);
    if(a>b)swap(a,b);
     long ret=0;
     long lo=0,hi=1e9,md;long ck=0;
    while(lo<=hi)
    {
      md=(lo+hi)/2;
      if((y-md*b>=x-md*a) && (y-md*b>=0) && (x-md*a>=0))
      {
        ck=md;lo=md+1;
      }
      else hi=md-1;
    }
    y-=ck*b,x-=ck*a;ret+=ck;
      lo=0,hi=1e9,md;
    while(lo<=hi)
    {
      md=(lo+hi)/2;
      if((y-md*(a+b)>=0) && (x-md*(a+b)>=0))
      {
        ck=md;lo=md+1;
      }
      else hi=md-1;
    }
    y-=ck*(a+b),x-=ck*(a+b);ret+=ck+ck;
     while(true)
    {
      if(x>y)swap(x,y);
      if((y>=b) && (x>=a))
      {
        y-=b,x-=a;ret++;
      }
      else break;
    }
     cout<<ret<<endl;
   }
     return 0;
}