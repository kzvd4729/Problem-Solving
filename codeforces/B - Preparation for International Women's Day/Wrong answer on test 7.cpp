/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/07/2019 21:20                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1133/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],fr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>aa[i],fr[aa[i]%k]++;
  int ans=0;
  for(int i=1;i<=k;i++)
    ans+=min(fr[i],fr[k-i]);
  cout<<ans+fr[0]-fr[0]%2<<endl;
  return 0;
}