/****************************************************************************************
*  @author: kzvd4729#                                        created: Nov/03/2020 14:46                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1428/problem/E
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
int a[N+2],b[N+2];
long sq(int x)
{
  return 1LL*x*x;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>a[i];
   sort(a+1,a+n+1,greater<int>());
  //for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
    int lo=1,hi=1e6,md,cnt;
  while(lo<hi)
  {
    md=(lo+hi)/2;cnt=0;
    for(int i=1;i<=n;i++)cnt+=(a[i]+md-1)/md;
     if(cnt>k)lo=md+1;else hi=md;
  }
  cnt=0;
  for(int i=1;i<=n;i++)cnt+=(a[i]+lo-1)/lo;
  long ans=0;
  for(int i=1;i<=n;i++)
  {
    int d=(a[i]+lo-1)/lo;if(cnt<k)cnt++,d++;
     assert(d<=a[i]);
    ans+=sq(a[i]/d)*(d-a[i]%d);ans+=sq(a[i]/d+1)*(a[i]%d);
  }
  cout<<ans<<endl;
  return 0;
}