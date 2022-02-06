/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/16/2018 17:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 4700 KB                              
*  problem: https://codeforces.com/contest/1041/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
long qm[N+2],ans;
struct segment
{
  long x,y;
}arr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,h;cin>>n>>h;
  for(long i=1;i<=n;i++)
    cin>>arr[i].x>>arr[i].y;
  for(long i=2;i<=n;i++)
    qm[i]=qm[i-1]+arr[i].x-arr[i-1].y;
  for(long i=1;i<=n;i++)
  {
    long lo=i,hi=n,md;
    while(hi-lo>3)
    {
      md=(lo+hi)/2;
      if(qm[md]-qm[i]>=h)hi=md;
      else lo=md;
    }
    for(md=hi;md>=lo;md--)
      if(qm[md]-qm[i]<h)break;
    long ds=qm[md]-qm[i];
    ans=max(ans,arr[md].y-arr[i].x+h-ds);
  }
  cout<<ans<<endl;
  return 0;
}