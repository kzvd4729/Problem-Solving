/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-28 14:46:49                      
*  solution_verdict: AC                                      language: C++ (GCC 9.2.1)                         
*  run_time: 49 ms                                           memory_used: 3572 KB                              
*  problem: https://atcoder.jp/contests/arc112/tasks/arc112_a
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
const int N=1e6,inf=1e9,mod=1000000007;
 long sm(int d)
{
  if(d<=0)return 0;
  return 1LL*d*(d+1)/2;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int l,r;cin>>l>>r;
     int d=(r-l+1);
    cout<<sm(d-l)<<endl;
   }
  return 0;
}