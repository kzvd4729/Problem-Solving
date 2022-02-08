/****************************************************************************************
*  @author: kzvd4729                                         created: 02-11-2018 19:49:36                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.02 sec                                        memory_used: 22.5M                                
*  problem: https://www.codechef.com/NOV18A/problems/GMEDIAN
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const long mod=1e9+7;
long ncr[N+2][N+2];
int aa[N+2];
void _ncr(void)
{
  for(int i=0;i<=N;i++)
    ncr[i][0]=1;
  for(int i=1;i<=N;i++)
  {
    for(int j=1;j<=N;j++)
    {
      ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  _ncr();
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)
      cin>>aa[i];
    sort(aa+1,aa+n+1);
    long ans=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=0; ;j++)
      {
        if(j>i-1||j>n-i)break;
        long a=ncr[i-1][j];
        long b=ncr[n-i][j];
        ans=(ans+a*b)%mod;
      }
      for(int k=i+1;k<=n;k++)
      {
        if(aa[k]!=aa[i])break;
        for(int j=0;j<=n;j++)
        {
          if(j>i-1||j>n-k)break;
          long a=ncr[i-1][j];
          long b=ncr[n-k][j];
          ans=(ans+a*b)%mod;
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}