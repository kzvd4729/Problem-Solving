/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/23/2021 20:38                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1517/problem/A
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
const long N=1e6,inf=1e9,mod=1e9+7;
 long sum(long x)
{
  long ret=0;
  while(x)
  {
    ret+=x%10;
    x/=10;
  }
  return ret;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long t;cin>>t;
  while(t--)
  {
    long n;cin>>n;
     long x=2050;
    if(n%x)
    {
      cout<<-1<<endl;continue;
    }
    long a=n/x;
     cout<<sum(a)<<endl;
  }
      return 0;
}