/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/28/2018 21:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/1043/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;int mx=0;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];mx=max(mx,aa[i]);
  }
  for( ; ;mx++)
  {
    int a=0,b=0;
    for(int i=1;i<=n;i++)
    {
      a+=mx-aa[i],b+=aa[i];
    }
    if(a>b)
    {
      cout<<mx<<endl,exit(0);
    }
  }
  return 0;
}