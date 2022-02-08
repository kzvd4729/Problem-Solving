/****************************************************************************************
*  @author: kzvd4729                                         created: 02-11-2018 23:01:39                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.06 sec                                        memory_used: 30.2M                                
*  problem: https://www.codechef.com/NOV18A/problems/GMEDIAN
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const long mod=1e9+7;
long ncr[N+2][N+2],qm[N+2][N+2],rgt[N+2];
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
//  for(int i=0;i<=5;i++)
//  {
//    for(int j=0;j<=5;j++)
//    {
//      cout<<ncr[i][j]<<" ";
//    }
//    cout<<endl;
//  }
  qm[0][0]=1;
  for(int i=1;i<=N;i++)
  {
    for(int j=0;j<=N;j++)
    {
      qm[i][j]=(qm[i-1][j]+ncr[i][j])%mod;
    }
  }
//  for(int i=0;i<=5;i++)
//  {
//    for(int j=0;j<=5;j++)
//    {
//      cout<<qm[i][j]<<" ";
//    }
//    cout<<endl;
//  }
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
    for(int i=n;i>=1;i--)
    {
      if(aa[i]==aa[i+1])rgt[i]=rgt[i+1];
      else rgt[i]=i;
    }
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
      //cout<<ans<<" ";
      int k=rgt[i];
      for(int j=0;j<=n;j++)
      {
        if(j>i-1)break;
        long a=ncr[i-1][j];
        long b=(qm[n-(i+1)][j]-qm[n-(k+1)][j]+mod)%mod;
        if(b<0)assert(0);
        ans=(ans+a*b)%mod;
      }
      //cout<<ans<<endl;
    }
    cout<<ans<<endl;
  }
  return 0;
}