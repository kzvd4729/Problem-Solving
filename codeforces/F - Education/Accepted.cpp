/****************************************************************************************
*  @author: * kzvd4729                                       created: Apr/10/2021 20:56                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 77 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1512/problem/F
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
 int a[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,c;cin>>n>>c;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<n;i++)cin>>b[i];
      long ans=1LL*inf*inf,day=0,money=0;
    for(int i=1;i<=n;i++)
    {
      ans=min(ans,day+( max(0LL,c-money)+ a[i]-1)/a[i]);
       long rq=( max(0LL,b[i]-money)+ a[i]-1)/a[i];
      day+=rq;money+=rq*a[i];
       day++;money-=b[i];
    }
    cout<<ans<<endl;
  }
    return 0;
}