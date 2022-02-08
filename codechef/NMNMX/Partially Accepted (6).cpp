/****************************************************************************************
*  @author: kzvd4729                                         created: 08-07-2018 22:25:46                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.03 sec                                        memory_used: 206.6M                               
*  problem: https://www.codechef.com/JULY18A/problems/NMNMX
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
const long N=5e3;
long t,n,k,arr[N+2];
long ncr[N+2][N+2];
void _ncr(void)
{
  for(long i=0;i<=N;i++)ncr[i][0]=1;
  for(long i=1;i<=N;i++)
    for(long j=1;j<=i;j++)
      ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
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
    long ans=1;
    for(long i=1;i<=n;i++)
    {
      long sm=i-1;
      long bg=n-i;
      long way=ncr[n-1][k-1];
      way+=4*mod;
      way-=ncr[sm][k-1];
      way-=ncr[bg][k-1];
      way%=mod;
      while(way>0)
      {
        ans=(ans*arr[i])%mod;
        way--;
      }
    }
    cout<<ans%mod<<endl;
  }
  return 0;
}