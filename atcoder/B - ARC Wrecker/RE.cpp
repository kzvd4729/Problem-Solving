/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-04-27 21:40:38                      
*  solution_verdict: RE                                      language: C++ (GCC 9.2.1)                         
*  run_time: 120 ms                                          memory_used: 3620 KB                              
*  problem: https://atcoder.jp/contests/arc117/tasks/arc117_b
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
const int N=1e2,inf=1e9,mod=1e9+7;
 int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
   sort(a+1,a+n+1);
   long ans=1;
  for(int i=1;i<=n;i++)
  {
    ans=(ans*(a[i]-a[i-1]+1))%mod;
  }
  cout<<ans<<endl;
    return 0;
}