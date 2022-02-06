/****************************************************************************************
*  @author: * kzvd4729                                       created: Oct/22/2019 20:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1249/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int q;cin>>q;
  while(q--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i];
    sort(aa+1,aa+n+1);
     int f=1;
    for(int i=2;i<=n;i++)
      if(aa[i]-aa[i-1]==1)f=2;
    cout<<f<<"\n";
  }
  return 0;
}