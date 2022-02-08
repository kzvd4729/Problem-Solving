/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-12-08 18:22:23                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 207 ms                                          memory_used: 147968 KB                            
*  problem: https://atcoder.jp/contests/abc147/tasks/abc147_d
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
const long mod=1e9+7;
long aa[N+2],cnt[N+2][62];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   for(int i=n;i>=1;i--)
  {
    for(int j=0;j<60;j++)
      cnt[i][j]=cnt[i+1][j]+(bool)(aa[i]&(1LL<<j));
  }
   long ans=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<60;j++)
    {
      bool f=(bool)(aa[i]&(1LL<<j));
      if(!f)ans=(ans+((1LL<<j)%mod)*cnt[i+1][j])%mod;
      else ans=(ans+((1LL<<j)%mod)*(n-i-cnt[i+1][j]))%mod;
    }
  }
  cout<<ans<<endl;
  return 0;
}