/****************************************************************************************
*  @author: * kzvd4729                                       created: May/28/2021 20:10                        
*  solution_verdict: Wrong answer on pretest 1               language: GNU C++17 (64)                          
*  run_time: 0 ms                                            memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1526/problem/A
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
 int a[N+2];
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n+n;i++)cin>>a[i];
     sort(a+1,a+n+n+1);
    for(int i=1;i<=n+n;i+=2)cout<<a[i]<<" ";
    for(int i=2;i<=n+n;i+=2)cout<<a[i]<<" ";cout<<endl;
  }
      return 0;
}