/****************************************************************************************
*  @author: kzvd4729#                                        created: Oct/10/2020 14:15                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/549/problem/H
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
//#define long long long
#define double long double
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   double a,b,c,d;cin>>a>>b>>c>>d;
   double z=0,lo=0,hi=1e9,md;int lp=200;
  while(lp--)
  {
    md=(lo+hi)/2.0;
     double mn1=max(z,a-md)*max(z,d-md);
    double mx1=(a+md)*(d+md);
     double mn2=max(z,b-md)*max(z,c-md);
    double mx2=(b+md)*(c+md);
     if(mn1>mx2||mx1<mn2)lo=md;else hi=md;
  }
  cout<<setprecision(10)<<fixed;
  cout<<md<<endl;
  return 0;
}