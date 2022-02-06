/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/18/2021 20:41                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1486/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 long a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)
      cin>>a[i];
     long pr=0;int f=1;
    for(int i=1;i<=n;i++)
    {
      a[i]+=pr;
      if(a[i]<i-1)f=0;
      pr=a[i]-(i-1);
    }
    if(f)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}