/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/20/2018 19:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/735/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;if(n==2)cout<<1<<endl,exit(0);
  aa[1]=2;aa[2]=3;
  for(int i=3; ;i++)
  {
    aa[i]=aa[i-1]+aa[i-2];
    if(aa[i]>n)
      cout<<i-1<<endl,exit(0);
  }
  return 0;
}