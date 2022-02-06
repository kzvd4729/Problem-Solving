/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/12/2019 23:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 23500 KB                             
*  problem: https://codeforces.com/contest/1119/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long unsigned long long
using namespace std;
const long N=1e6;
long aa[N+2],df[N+2],qm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  for(long i=1;i<=n;i++)cin>>aa[i];
  sort(aa+1,aa+n+1);
    for(long i=1;i<n;i++)
    df[i]=aa[i+1]-aa[i];
  sort(df+1,df+n);
   for(long i=1;i<n;i++)
    qm[i]=qm[i-1]+df[i];
   long q;cin>>q;
  while(q--)
  {
    long lt,rt;cin>>lt>>rt;
    long lo=0,hi=n-1,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(df[md]<=rt-lt+1)
        lo=md;
      else hi=md;
    }
    for(md=hi;md>=lo;md--)
    {
      if(df[md]<=rt-lt+1)
        break;
    }
    cout<<qm[md]+(n-md)*(rt-lt+1)<<"\n";
  }
  return 0;
}