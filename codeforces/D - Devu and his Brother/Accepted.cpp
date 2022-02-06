/****************************************************************************************
*  @author: kzvd4729#                                        created: May/29/2020 21:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 31300 KB                             
*  problem: https://codeforces.com/contest/439/problem/D
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
#include<unordered_map>
#include<random>
#include<chrono>
#define long long long
using namespace std;
const long N=1e6;
long a[N+2],b[N+2],aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m;cin>>n>>m;
  for(long i=1;i<=n;i++)cin>>a[i];
  for(long i=1;i<=m;i++)cin>>b[i];
   sort(a+1,a+n+1);sort(b+1,b+m+1);
  for(long i=1;i<=n;i++)aa[i]=aa[i-1]+a[i];
  for(long i=m;i>=1;i--)bb[i]=bb[i+1]+b[i];
   auto ret=[&](long md)
  {
    long now=0;
    long id=upper_bound(b+1,b+m+1,md)-b;
    now+=bb[id]-1LL*md*(m-id+1);
     id=upper_bound(a+1,a+n+1,md)-a;id--;
    now+=1LL*md*id-aa[id];
    return now;
  };
  long lo=0,hi=1e9,md1,md2;
  while(hi-lo>10)
  {
    md1=(lo+lo+hi)/3;
    md2=(lo+hi+hi)/3;
    if(ret(md1)<=ret(md2))hi=md2;
    else lo=md1;
  }
  long ans=1e18;
  for(long md=lo;md<=hi;md++)ans=min(ans,ret(md));
  cout<<ans<<endl;
   return 0;
}