/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/10/2021 21:01                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++17 (64)                          
*  run_time: 30 ms                                           memory_used: 0 KB                                 
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
const int N=1e6,inf=1e9,mod=1e9+7;
  int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int x,y,a,b;cin>>x>>y>>a>>b;
     if(x>y)swap(x,y);
    if(a>b)swap(a,b);
     int mx=(x+y)/(a+b);
    int tw=x/a,fv=y/b;
     if(tw<fv)cout<<tw<<endl;
    else cout<<mx<<endl;
  }
     return 0;
}