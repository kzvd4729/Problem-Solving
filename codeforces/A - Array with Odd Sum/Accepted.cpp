/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/04/2020 20:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1296/problem/A
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
    int n;cin>>n;int sm=0,od=0,ev=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;sm+=x;
      if(x%2)od++;else ev++;
    }
    if(sm%2||(od&&ev))cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}