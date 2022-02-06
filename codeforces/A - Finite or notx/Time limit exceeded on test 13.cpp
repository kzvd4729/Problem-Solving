/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/19/2020 12:02                        
*  solution_verdict: Time limit exceeded on test 13          language: GNU C++17                               
*  run_time: 1000 ms                                         memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/983/problem/A
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long p,q,b;cin>>p>>q>>b;
    long g=__gcd(p,q);q/=g;
     while(true)
    {
      long g=__gcd(q,b);
      q/=g;if(g==1)break;
    }
    if(q==1)cout<<"Finite\n";else cout<<"Infinite\n";
  }
   return 0;
}