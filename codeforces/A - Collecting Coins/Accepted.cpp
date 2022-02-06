/****************************************************************************************
*  @author: * kzvd4729                                       created: Jan/22/2020 20:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1294/problem/A
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
    int a,b,c,n;cin>>a>>b>>c>>n;
    int mx=max({a,b,c});
    n=n-(3*mx-a-b-c);
    if(n<0||n%3)cout<<"NO\n";else cout<<"YES\n";
  }
    return 0;
}