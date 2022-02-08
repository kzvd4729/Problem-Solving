/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-10 18:24:09                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 14 ms                                           memory_used: 1024 KB                              
*  problem: https://atcoder.jp/contests/abc150/tasks/abc150_d
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e9;
long aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m;cin>>n>>m;
   long lcm=1;
  for(long i=1;i<=n;i++)
  {
    long x;cin>>x;x/=2;aa[i]=x;
    lcm=(lcm*x)/__gcd(lcm,x);
    if(lcm>m)cout<<0<<endl,exit(0);
  }
  //cout<<lcm<<endl;
  //cout<<"here"<<endl;
  for(int i=1;i<=n;i++)
  {
    if((lcm/aa[i])%2==0)cout<<0<<endl,exit(0);
  }
  cout<<((m/lcm)+1)/2<<endl;
   return 0;
}