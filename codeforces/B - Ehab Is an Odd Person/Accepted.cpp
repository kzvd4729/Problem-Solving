/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/16/2019 19:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1174/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],f[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<=n;i++)f[aa[i]%2]=1;
  if(f[0]&&f[1])sort(aa+1,aa+n+1);
  for(int i=1;i<=n;i++)
    cout<<aa[i]<<" ";
  cout<<endl;
  return 0;
}