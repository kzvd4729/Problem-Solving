/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/19/2020 11:45                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++17                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1103/problem/B
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
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   while(true)
  {
    string s;cin>>s;
    if(s=="end")break;
    else if(s=="mistake")assert(0);
     int a=1,b=2;
    while(true)
    {
      if(a>inf)assert(0);
      cout<<"? "<<a<<" "<<b<<endl;
      char c;cin>>c;
       if(c=='x')break;
      a=b;b+=b;
    }
    if(a==1&&b==2)
    {
      cout<<"? "<<2<<" "<<3<<endl;
      char c;cin>>c;
      if(c=='x')cout<<"! "<<1<<endl;
      else cout<<"! "<<2<<endl;
      continue;
    }
    int lo=a+1,hi=b,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      cout<<"? "<<a<<" "<<md<<endl;
      char c;cin>>c;
      if(c=='x')hi=md;else lo=md;
    }
    for(md=lo;md<=hi;md++)
    {
      cout<<"? "<<a<<" "<<md<<endl;
      char c;cin>>c;
      if(c=='x')break;
    }
    cout<<"! "<<md<<endl;
  }
  return 0;
}