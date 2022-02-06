/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/29/2019 20:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1263/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>a[1]>>a[2]>>a[3];sort(a+1,a+3+1);
    if(a[3]>a[1]+a[2])cout<<a[1]+a[2]<<"\n";
    else cout<<(a[1]+a[2]+a[3])/2<<"\n";
  }
  return 0;
}