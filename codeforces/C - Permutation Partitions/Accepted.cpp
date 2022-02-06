/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/06/2020 10:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1326/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=998244353;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
   int ans=1,pr=-1;
  for(int i=1;i<=n;i++)
  {
    if(aa[i]>=n-k+1)
    {
      if(pr==-1)pr=i;
      else
      {
        ans=(1LL*ans*(i-pr))%mod;
        pr=i;
      }
    }
  }
  long ad=0;
  for(int i=n;i>=n-k+1;i--)ad+=i;
  cout<<ad<<" "<<ans<<endl;
  return 0;
}