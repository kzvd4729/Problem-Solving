/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/10/2020 13:34                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1327/problem/A
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
    long n,k;cin>>n>>k;
    long p=1LL*k*k;
     if(p>n||(n-p)%2)cout<<"NO\n";else cout<<"YES\n";
  }
  return 0;
}