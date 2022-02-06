/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/19/2020 18:30                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/794/problem/B
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
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e6;
double ar(double b,double h)
{
  return 0.5*b*h;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;double h;cin>>h;
   double un=ar(1,h)/(n*1.0);
  double tr=0;
   for(int i=1;i<n;i++)
  {
    tr+=un;//cout<<tr<<endl;
    double lo=0,hi=h,md;int loop=100;
    while(loop--)
    {
      md=(lo+hi)/2.0;
      double b=md/(h*1.0);
      if(ar(b,md)>tr)hi=md;else lo=md;
    }
    cout<<setprecision(9)<<fixed<<md<<"\n";
  }
  return 0;
}