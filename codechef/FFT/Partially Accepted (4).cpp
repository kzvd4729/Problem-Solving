/****************************************************************************************
*  @author: kzvd4729                                         created: 23-04-2020 16:58:33                      
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
  for(int i=1;i<=n;i++)cnt[i]=0;
  int f=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;if(x>n)f=1;
    cnt[x]++;
  }
  if(f)return 0;
  long ans=1;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=cnt[i];j++)
      if(j%i)ans=(ans*j)%mod;
  }
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