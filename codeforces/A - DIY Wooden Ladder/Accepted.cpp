/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/27/2019 14:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/1197/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
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
    cout<<min(n-2,aa[n-1]-1)<<"\n";
  }
  return 0;
}