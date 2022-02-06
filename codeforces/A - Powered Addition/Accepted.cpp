/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/13/2020 09:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1338/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;for(int i=1;i<=n;i++)cin>>aa[i];
    int pr=-1e9,mx=0;
    for(int i=1;i<=n;i++)
    {
      mx=max(mx,pr-aa[i]);
      pr=max(pr,aa[i]);
    }
    if(mx==0)cout<<0<<endl;
    else cout<<32-__builtin_clz(mx)<<endl;
  }
  return 0;
}