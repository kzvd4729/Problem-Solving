/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/12/2020 16:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1334/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long;
using namespace std;
const int N=1e6;
int a[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;int f=0;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
     for(int i=1;i<=n;i++)
    {
      if(b[i]-b[i-1]>a[i]-a[i-1])f=1;
      if(a[i]<a[i-1]||b[i]<b[i-1])f=1;
    }
    if(f)cout<<"NO\n";else cout<<"YES\n";
  }
  return 0;
}