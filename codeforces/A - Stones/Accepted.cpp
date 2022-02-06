/****************************************************************************************
*  @author: * kzvd4729                                       created: Oct/17/2019 19:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1236/problem/A
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
    int a,b,c;cin>>a>>b>>c;
    int ans=0;
    int mn=min(b,c/2);
    b-=mn;
    ans+=mn*3;
    ans+=min(a,b/2)*3;
     cout<<ans<<"\n";
  }
  return 0;
}