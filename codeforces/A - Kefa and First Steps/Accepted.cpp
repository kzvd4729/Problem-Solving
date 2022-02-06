/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/16/2018 15:36                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/580/problem/A
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
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  int cnt=0,ans=0;
  for(int i=1;i<=n;i++)
  {
    if(aa[i]>=aa[i-1])cnt++;
    else cnt=1;
    ans=max(ans,cnt);
  }
  cout<<ans<<endl;
  return 0;
}