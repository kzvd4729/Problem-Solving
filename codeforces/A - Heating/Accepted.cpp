/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/27/2019 19:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1260/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
     int a=k/n;int md=k%n;
    cout<<1LL*(a+1)*(a+1)*md+1LL*a*a*(n-md)<<"\n";
  }
  return 0;
}