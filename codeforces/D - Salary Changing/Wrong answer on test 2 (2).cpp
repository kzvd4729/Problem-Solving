/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/24/2019 21:54                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1251/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long n,vis[N+2];long s;
vector<pair<long,long> >v;
bool ok(long md)
{
  for(long i=0;i<n;i++)vis[i]=0;
  long cnt=(n+1)/2;
  for(long i=n-1;i>=0;i--)
  {
    if(v[i].second>=md&&cnt)vis[i]=1,cnt--;
  }
  if(cnt)return false;long ss=s;
  ss-=(1LL*md*((n+1)/2));if(ss<0)return false;
   for(long i=0;i<n;i++)
  {
    if(!vis[i])ss-=v[i].first;
    if(ss<0)return false;
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    cin>>n>>s;v.resize(n);
    for(long i=0;i<n;i++)cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end());
     long lo=v[n/2].first,hi=1e9,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(ok(md))lo=md;else hi=md;
    }
    for(md=hi;md>=lo;md--)
      if(ok(md))break;
    cout<<md<<"\n";
  }
  return 0;
}