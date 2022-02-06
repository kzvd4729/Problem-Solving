/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/34/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  sort(aa+1,aa+n+1);
  int ans=0;
  for(int i=1;i<=m;i++)
    ans+=max(0,-aa[i]);
  cout<<ans<<endl;
   return 0;
}