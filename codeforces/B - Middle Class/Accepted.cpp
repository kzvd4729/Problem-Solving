/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/12/2020 16:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1334/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
int aa[N+2],bb[N+2];long cc[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long n,x;cin>>n>>x;long a=0,b=0;
    for(long i=1;i<=n;i++)
    {
      long z;cin>>z;
      if(z>=x)aa[++a]=z;
      else bb[++b]=z;
    }
    sort(aa+1,aa+a+1,greater<int>());
    sort(bb+1,bb+b+1,greater<int>());
     for(long i=1;i<=b;i++)cc[i]=cc[i-1]+bb[i];
     long ans=a,sm=0;
    for(long i=1;i<=a;i++)
    {
      sm+=aa[i];long lo=1,hi=b,md;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(sm+cc[md]>=x*(i+md))lo=md;
        else hi=md;
      }
      for(md=lo;md<=hi;md++)
      {
        if(sm+cc[md]>=x*(i+md))ans=max(ans,a+md);
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}