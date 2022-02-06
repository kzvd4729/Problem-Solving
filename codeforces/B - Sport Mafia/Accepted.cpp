/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/17/2019 20:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1195/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,k,a;cin>>n>>k;
  for(a=1;a<=n;a+=1000)
  {
    long b=a+1000;if(b>n)break;
    long sm=(b*(b+1))/2-(n-b);
    if(sm>=k)break;
  }
  for(long b=a;b<=n;b++)
  {
    long sm=(b*(b+1))/2-(n-b);
    if(sm==k)cout<<n-b<<endl,exit(0);
  }
  assert(0);
  return 0;
}