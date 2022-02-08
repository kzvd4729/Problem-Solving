/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-21 16:28:13                      
*  solution_verdict: WA                                      language: C++ (GCC 9.2.1)                         
*  run_time: 6 ms                                            memory_used: 3492 KB                              
*  problem: https://atcoder.jp/contests/arc113/tasks/arc113_b
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
const int N=1e6,inf=1e9;
 __int128 big(__int128 b,__int128 p,__int128 mod)
{
  __int128 r=1;
  while(p)
  {
    if(p&1)r=(r*b)%mod;b=(b*b)%mod;p/=2;
  }
  return r;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int a,b,c;cin>>a>>b>>c;
   __int128 mod=4;
  for(int i=1;i<=9;i++)mod*=10;
   __int128 p=big(b,c,mod);
   mod=10;
  for(int i=1;i<=9;i++)mod*=10;
  __int128 ans=big(a,p,mod);
   int pr=ans%10;
  cout<<pr<<endl;
     return 0;
}