/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/04/2021 20:38                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1535/problem/A
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
    int a,b,c,d;cin>>a>>b>>c>>d;
     int f=0;
    if(a>b)
    {
      if(b>c && b>d)f=1;
    }
    if(b>a)
    {
      if(a>c && a>d)f=1;
    }
     if(c>d)
    {
      if(d>a && d>b)f=1;
    }
    if(d>c)
    {
      if(c>a && c>b)f=1;
    }
    if(f)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
  }
       return 0;
}