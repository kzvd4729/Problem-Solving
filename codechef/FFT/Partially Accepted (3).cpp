/****************************************************************************************
*  @author: kzvd4729                                         created: 23-04-2020 16:56:12                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.06 sec                                        memory_used: 22.5M                                
*  problem: https://www.codechef.com/problems/FFT
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const int mod=998244353;
int cnt[N+2],aa[N+2];
int solve(int n)
{
  //for(int i=1;i<=n;i++)cnt[i]=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;//if(x>n)assert(0);
    cnt[x]++;aa[i]=x;
  }
  long ans=1;
  for(int i=1;i<=n;i++)
  {
    //if(cnt[i]%i)assert(0);
    //if(cnt[i])ans=(ans*fac[cnt[i]-1])%mod;
    for(int j=1;j<=cnt[i];j++)
      if(j%i)ans=(ans*j)%mod;
  }
  for(int i=1;i<=n;i++)cnt[aa[i]]--;
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;cout<<solve(n)<<"\n";
  }
  return 0;
}