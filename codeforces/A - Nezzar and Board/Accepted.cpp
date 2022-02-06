/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/02/2021 14:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1477/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
long a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
     sort(a+1,a+n+1);long gc=0;
    for(int i=2;i<=n;i++)
      gc=__gcd(gc,a[i]-a[i-1]);
     int f=0;
    for(int i=1;i<=n;i++)
    {
      if((k-a[i])%gc==0)f=1;
    }
    if(f)cout<<"YES\n";else cout<<"NO\n";
  }
    return 0;
}