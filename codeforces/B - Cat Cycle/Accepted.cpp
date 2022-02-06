/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2021 20:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1487/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    if((n%2)==0)
    {
      k%=n;
      if(k==0)k=n;
      cout<<k<<endl;
    }
    else
    {
      long lo=0,hi=inf*3LL,md;
      long sk=(n+1)/2;
      while(hi-lo>10)
      {
        md=(lo+hi)/2;
        if(md-md/sk>=k)hi=md;
        else lo=md;
      }
      for(md=lo;md<=hi;md++)
      {
        if(md-md/sk==k)break;
      }
      md%=n;
      if(md==0)md=n;
      cout<<md<<endl;
     }
  }
   return 0;
}