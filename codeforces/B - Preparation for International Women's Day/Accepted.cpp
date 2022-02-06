/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/07/2019 21:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 7800 KB                              
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
  int ans=fr[0]-fr[0]%2;
  if(k%2==0)ans=ans+fr[k/2]-fr[k/2]%2;
  for(int i=1;i<(k+1)/2;i++)
    ans+=min(fr[i],fr[k-i])*2;
  cout<<ans<<endl;
  return 0;
}