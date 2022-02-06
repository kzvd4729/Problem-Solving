/****************************************************************************************
*  @author: kzvd4729                                         created: May/13/2019 15:36                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 248 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/273/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  int m;cin>>m;long mx=0;
  while(m--)
  {
    int w,h;cin>>w>>h;
    mx=max(mx,aa[w]*1LL);
    cout<<mx<<"\n";mx+=h*1LL;
  }
  return 0;
}