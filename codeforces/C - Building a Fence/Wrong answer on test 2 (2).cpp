/****************************************************************************************
*  @author: kzvd4729#                                        created: Apr/18/2021 13:05                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++17 (64)                          
*  run_time: 61 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1469/problem/C
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
  long a[N+2];
 bool solve()
{
  long n,k;cin>>n>>k;
  for(long i=1;i<=n;i++)cin>>a[i];
   long lo=a[1],hi=a[1]+k;
   for(long i=2;i<n;i++)
  {
    lo=lo-k+1,hi--;
     lo=max(a[i],lo);
        if(i<n)hi=min(a[i]+k-1,hi);
    else hi=min(a[i],hi);
     if(lo>hi)return false;
     hi+=k;
  }
  //cout<<lo<<" --> "<<hi<<endl;
   return true;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long t;cin>>t;
  while(t--)
  {
    if(solve())cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}