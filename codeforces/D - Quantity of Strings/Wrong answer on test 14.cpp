/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/02/2018 23:08                        
*  solution_verdict: Wrong answer on test 14                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/151/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
int n,m,k;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m>>k;
   if(k>n)
  {
    long ans=1;
    for(int i=1;i<=n;i++)
      ans=(ans*m)%mod;
    cout<<ans<<endl;
    return 0;
  }
  if(n==1)cout<<m<<endl,exit(0);
  if(k==n)
  {
    long ans=1;
    for(int i=1;i<=(n+1)/2;i++)
      ans=(ans*m)%mod;
    cout<<ans<<endl;
    return 0;
  }
  if(k+1==n&&k%2)
  {
    cout<<m*m<<endl;
    return 0;
  }
  cout<<m<<endl;
  return 0;
}