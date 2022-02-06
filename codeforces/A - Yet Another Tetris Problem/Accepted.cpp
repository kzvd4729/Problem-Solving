/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/12/2020 19:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1324/problem/A
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
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i];
    sort(aa+1,aa+n+1);
    for(int i=2;i<=n;i++)aa[i]-=aa[1];
     int f=0;
    for(int i=2;i<=n;i++)
      if(aa[i]%2)f=1;
    if(f)cout<<"NO\n";else cout<<"YES\n";
  }
  return 0;
}