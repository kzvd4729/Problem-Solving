/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/18/2020 20:27                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 202 ms                                          memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/975/problem/C
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
const int N=2e5;
long a[N+2];int n;
int search(long x)
{
  int lo=1,hi=n+1,md;
  while(lo<hi)
  {
    md=(lo+hi)/2;
    if(a[md]>x)hi=md;else lo=md+1;
  }
  return lo-1;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>a[i],a[i]+=a[i-1];
   long ad=0;
  for(int i=1;i<=m;i++)
  {
    long x;cin>>x;ad+=x;
    int ans=n-search(ad);if(ans==0)ans=n,ad=0;
    cout<<ans<<'\n';
  }
  return 0;
}