/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/22/2018 10:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 248 ms                                          memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/236/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long ans,tw,n;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
   if(n==1)cout<<1<<endl,exit(0);
  if(n==2)cout<<2<<endl,exit(0);
  if(n==3)cout<<6<<endl,exit(0);
   if(n&1)cout<<n*(n-1)*(n-2)<<endl;
  else
  {
    tw=n*(n-1);
    for(int i=1;i<=n-2;i++)ans=max(ans,tw*i*1LL/__gcd(tw,i*1LL));
    cout<<max(ans,(n-1)*(n-2)*(n-3))<<endl;
  }
  return 0;
}