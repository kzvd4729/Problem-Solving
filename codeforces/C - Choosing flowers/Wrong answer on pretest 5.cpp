/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/19/2020 16:02                        
*  solution_verdict: Wrong answer on pretest 5               language: GNU C++17                               
*  run_time: 109 ms                                          memory_used: 27100 KB                             
*  problem: https://codeforces.com/contest/1379/problem/C
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
#define endl '\n'
#define long long long  
using namespace std;
const long N=1e6;
pair<long,long>a[N+2];
long sm[N+2];
long solve()
{
  long m;long n;cin>>m>>n;
  for(long i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
   sort(a+1,a+n+1,[&](pair<long,long>p1,pair<long,long>p2){
    return p1.first>p2.first;
  });
    for(long i=1;i<=n;i++)sm[i]=sm[i-1]+a[i].first;
   if(m==1)return a[1].first;
   //for(int i=1;i<=n;i++)cout<<a[i].first<<" --> "<<a[i].second<<endl;
   long ans=0;if(m<=n)ans=sm[m];
  for(long i=1;i<=n;i++)
  {
    long lo=1,hi=n,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(a[md].first>a[i].second)lo=md;
      else hi=md;
    }
    for(md=lo;md<=hi;md++)
      if(a[md].first<=a[i].second)break;
    md--;
     md=min(md,m-2);
    if(md<i)ans=max(ans,sm[md]+a[i].first+a[i].second*(m-md-1));
    else ans=max(ans,sm[md]+max(a[md+1].first,a[i].second)+a[i].second*(m-md-1));
  }
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    cout<<solve()<<endl;
  }
  return 0;
}