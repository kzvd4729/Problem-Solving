/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/17/2020 21:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1307/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,d;cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>aa[i];
     int mx=0,f=0;
    for(int i=1;i<=n;i++)
    {
      if(aa[i]==d)f=1;mx=max(mx,aa[i]);
    }
    if(f)cout<<1<<"\n";
    else cout<<max(2,(d+mx-1)/mx)<<"\n";
  }
  return 0;
}