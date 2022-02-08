/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-12-01 18:44:56                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 10 ms                                           memory_used: 4736 KB                              
*  problem: https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_e
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int aa[N+2],cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i],aa[i]++;
   int ans=1;cnt[0]=3;
  for(int i=1;i<=n;i++)
  {
    ans=(1LL*ans*(cnt[aa[i]-1]-cnt[aa[i]]))%mod;
    cnt[aa[i]]++;
  }
  cout<<ans<<endl;
  return 0;
}