/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/05/2021 20:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1481/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
int a[N+2];
int roll(int n)
{
  for(int i=1;i<n;i++)
  {
    if(a[i]<a[i+1])
    {
      a[i]++;
      return i;
    }
  }
  return -1;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
     int ans=0;
    for(int i=1;i<=k;i++)
    {
      ans=roll(n);
      if(ans==-1)break;
    }
    cout<<ans<<'\n';
  }
  return 0;
}