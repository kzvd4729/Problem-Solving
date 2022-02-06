/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/28/2021 19:56                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 15 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1491/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,u,v;cin>>n>>u>>v;
    for(int i=1;i<=n;i++)cin>>a[i];
    int f1=0,f2=0;
    for(int i=2;i<=n;i++)
    {
      if(abs(a[i]-a[i-1])>1)f1=1;
      if(abs(a[i]-a[i-1])>0)f2=1;
    }
    if(f1)cout<<0<<'\n';
    else if(f2)cout<<min(u,v)<<'\n';
    else cout<<min(u+v,v+v)<<'\n';
  }
    return 0;
}