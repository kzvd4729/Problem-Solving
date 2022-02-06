/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/17/2019 20:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1195/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;cnt[x]++;
  }
  int ans=0,od=0;
  for(int i=1;i<=k;i++)
  {
    if(cnt[i]%2==0)ans+=cnt[i];
    else ans+=cnt[i]-1,od++;
  }
  cout<<ans+(od+1)/2<<endl;
  return 0;
}