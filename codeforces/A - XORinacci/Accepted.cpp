/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/25/2019 20:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1208/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int a,b,n;cin>>a>>b>>n;
    if(n%3==0)cout<<a<<"\n";
    else if(n%3==1)cout<<b<<"\n";
    else cout<<(a^b)<<"\n";
  }
  return 0;
}