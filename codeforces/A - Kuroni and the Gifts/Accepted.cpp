/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/03/2020 20:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1305/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i];
    for(int i=1;i<=n;i++)cin>>bb[i];
     sort(aa+1,aa+n+1);sort(bb+1,bb+n+1);
    for(int i=1;i<=n;i++)cout<<aa[i]<<" ";cout<<endl;
    for(int i=1;i<=n;i++)cout<<bb[i]<<" ";cout<<endl;
  }
  return 0;
}