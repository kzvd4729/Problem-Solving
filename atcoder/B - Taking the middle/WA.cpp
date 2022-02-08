/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-05 15:41:51                      
*  solution_verdict: WA                                      language: C++ (GCC 9.2.1)                         
*  run_time: 47 ms                                           memory_used: 4780 KB                              
*  problem: https://atcoder.jp/contests/agc053/tasks/agc053_b
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
   int n;cin>>n;
   vector<int>a(n+n+2);
  for(int i=1;i<=n+n;i++)cin>>a[i];
   long sm=0;
  for(int i=1;i<=n;i++)
    sm+=max(a[i],a[n+n-i+1]);
   cout<<sm<<endl;
      return 0;
}