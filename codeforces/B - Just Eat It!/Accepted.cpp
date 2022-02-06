/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/10/2020 20:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1285/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e17;
long aa[N+2],mx[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long t;cin>>t;
  while(t--)
  {
    long n;cin>>n;long sm=0;
    for(long i=1;i<=n;i++)
      cin>>aa[i],sm+=aa[i];
     for(long i=0;i<=n+2;i++)mx[i]=0;
     long ans=-inf;
    for(long i=2;i<=n;i++)
    {
      mx[i]=mx[i-1]+aa[i];mx[i]=max(mx[i],aa[i]);
      ans=max(ans,mx[i]);
    }
     for(long i=0;i<=n+2;i++)mx[i]=0;
    for(long i=1;i<n;i++)
    {
      mx[i]=mx[i-1]+aa[i];mx[i]=max(mx[i],aa[i]);
      ans=max(ans,mx[i]);
    }
    if(sm>ans)cout<<"YES\n";else cout<<"NO\n";
  }
  return 0;
}