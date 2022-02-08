/****************************************************************************************
*  @author: kzvd4729                                         created: 16-07-2018 00:26:34                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.04 sec                                        memory_used: 206.6M                               
*  problem: https://www.codechef.com/JULY18A/problems/NMNMX
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
const long N=5e3;
long t,n,k,arr[N+2],ans;
long ncr[N+2][N+2];
void _ncr(void)
{
  for(long i=0;i<=N;i++)
    ncr[i][0]=1LL;
  for(long i=1;i<=N;i++)
    for(long j=1;j<=i;j++)
      ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
}
long bigmod(long b,long p)
{
  long ret=1LL;
  while(p)
  {
    if(p%2)ret=(ret*b)%mod;
    b=(b*b)%mod;
    p/=2;
  }
  return ret%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  _ncr();
  cin>>t;
  while(t--)
  {
    cin>>n>>k;
    for(long i=1;i<=n;i++)
      cin>>arr[i];
    sort(arr+1,arr+n+1);
    ans=1LL;
    for(long i=1;i<=n;i++)
    {
      long tmp=ncr[n-1][k-1];
      long sm=i-1;
      long bg=n-i;
      tmp=(tmp-ncr[sm][k-1]+mod)%mod;
      tmp=(tmp-ncr[bg][k-1]+mod)%mod;
      ans=(ans*bigmod(arr[i],tmp))%mod;
    }
    cout<<ans<<endl;
  }
  return 0;
}