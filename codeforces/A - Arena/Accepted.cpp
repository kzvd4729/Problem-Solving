/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2021 20:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1487/problem/A
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
    int n;cin>>n;int mn=inf;
    for(int i=1;i<=n;i++)
    {
      cin>>a[i];mn=min(mn,a[i]);
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
      cnt+=(mn==a[i]);
    cout<<n-cnt<<endl;
  }
   return 0;
}