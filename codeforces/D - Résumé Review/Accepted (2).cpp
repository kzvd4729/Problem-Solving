/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/07/2020 22:46                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 1715 ms                                         memory_used: 19300 KB                             
*  problem: https://codeforces.com/contest/1344/problem/D
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
#include<stack>
#include<deque>
#define long long long  
using namespace std;
const int N=1e6;
int a[N+2],sv[N+2],n;
long cal(__int128 now)
{
  long tk=0;
  for(int i=1;i<=n;i++)
  {
    if(now>a[i]-1)continue;
    int lo=1,hi=a[i],md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      md--;__int128 x=a[i]-1LL*md*md;x*=md;
      md++;__int128 y=a[i]-1LL*md*md;y*=md;
       if(y-x>=now)lo=md;else hi=md;
    }
    for(md=lo;md<=hi;md++)
    {
      md--;__int128 x=a[i]-1LL*md*md;x*=md;
      md++;__int128 y=a[i]-1LL*md*md;y*=md;
       if(y-x<now)break; 
    }
    md--;tk+=md;sv[i]=md;
  }
  return tk;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>a[i];
   __int128 mx=1;for(int i=1;i<=27;i++)mx*=10;
    __int128 lo=-mx,hi=mx,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;long x=cal(md);
    if(x<k)hi=md;else lo=md;
  }
  for(md=lo;md<=hi;md++)
  {
    long x=cal(md);if(x<=k)break;
  }
  for(int i=1;i<=n;i++)k-=sv[i];
  assert(k<=N);
  priority_queue<pair<__int128,int> >pq;
  for(int i=1;i<=n;i++)
  {
    if(sv[i]==a[i])continue;int md=sv[i];
    __int128 x=a[i]-1LL*md*md;x*=md;
    md++;__int128 y=a[i]-1LL*md*md;y*=md;
    pq.push({y-x,i});
  }
  while(k--)
  {
    pair<__int128,int>p=pq.top();pq.pop();
    int i=p.second;
    int md=++sv[i];if(md==a[i])continue;
     __int128 x=a[i]-1LL*md*md;x*=md;
    md++;__int128 y=a[i]-1LL*md*md;y*=md;
    pq.push({y-x,i});
  }
  for(int i=1;i<=n;i++)cout<<sv[i]<<" ";cout<<endl;
  return 0;
}