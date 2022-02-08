/****************************************************************************************
*  @author: kzvd4729                                         created: 02-11-2018 23:40:31                      
*  solution_verdict: Time Limit Exceeded                     language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/NOV18A/problems/GMEDIAN
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e3;
const long mod=1e9+7;
long ncr[N+2][N+2],qm[N+2][N+2],rgt[N+2];
long aa[N+2];
void _ncr(void)
{
  for(long i=0;i<=N;i++)
    ncr[i][0]=1;
  for(long i=1;i<=N;i++)
  {
    for(long j=1;j<=N;j++)
    {
      ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
    }
  }
//  for(long i=0;i<=5;i++)
//  {
//    for(long j=0;j<=5;j++)
//    {
//      cout<<ncr[i][j]<<" ";
//    }
//    cout<<endl;
//  }
  qm[0][0]=1;
  for(long i=1;i<=N;i++)
  {
    for(long j=0;j<=N;j++)
    {
      qm[i][j]=(qm[i-1][j]+ncr[i][j])%mod;
    }
  }
//  for(long i=0;i<=5;i++)
//  {
//    for(long j=0;j<=5;j++)
//    {
//      cout<<qm[i][j]<<" ";
//    }
//    cout<<endl;
//  }
}
int main()
{
//  ifstream cin("out.txt");
//  ofstream cout("sub.txt");
  ios_base::sync_with_stdio(0);cin.tie(0);
  _ncr();
  long t;cin>>t;
  while(t--)
  {
    memset(aa,-1,sizeof(aa));
    memset(rgt,-1,sizeof(rgt));
    long n;cin>>n;
    for(long i=1;i<=n;i++)
      cin>>aa[i];
    sort(aa+1,aa+n+1);
    for(long i=n;i>=1;i--)
    {
      if(aa[i]==aa[i+1])rgt[i]=rgt[i+1];
      else rgt[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
      if(rgt[i]<=0)assert(0);
      if(rgt[i]>n)assert(0);
    }
    long ans=0;
    for(long i=1;i<=n;i++)
    {
      for(long j=0; ;j++)
      {
        //if(j>i-1||j>n-i)break;
        long a=ncr[i-1][j];
        long b=ncr[n-i][j];
        ans=(ans+a*b)%mod;
      }
      //cout<<ans<<" ";
      long k=rgt[i];
      for(long j=0;j<=n;j++)
      {
        //if(j>i-1)break;
        long a=ncr[i-1][j];
        long b=(qm[n-(i+1)][j]-qm[n-(k+1)][j]+mod)%mod;
        if(b<0)assert(0);
        ans=(ans+a*b)%mod;
      }
      //cout<<ans<<endl;
    }
    if(ans<=0)assert(0);
    cout<<ans<<endl;
  }
  return 0;
}