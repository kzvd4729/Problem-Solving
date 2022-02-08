/****************************************************************************************
*  @author: kzvd4729                                         created: 03-11-2018 00:14:41                      
*  solution_verdict: Run Time Error(SIGSEGV)                 language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/NOV18A/problems/GMEDIAN
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e2;
const long mod=1e9+7;
long ncr[N+2][N+2],qm[N+2][N+2],rgt[N+2];
int aa[N+2];
void _ncr(void)
{
  for(int i=0;i<=N;i++)
  {
    ncr[i][0]=1;
    qm[i][0]=1;
  }
  for(int i=1;i<=N;i++)
  {
    for(int j=1;j<=N;j++)
    {
      ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
      qm[i][j]=ncr[i][j];
    }
  }
//  for(int j=0;j<=N;j++)
//  {
//    for(int i=1;i<=N;i++)
//    {
//      qm[i][j]=(qm[i-1][j]+ncr[i][j])%mod;
//    }
//  }
  for(int j=0;j<=N;j++)
  {
    for(int i=0;i<=N;i++)
    {
      long sum=0;
      for(int k=0;k<=i;k++)
        sum=(sum+ncr[k][j])%mod;
      qm[i][j]=sum;
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
}
int main()
{
//  ifstream cin("out.txt");
//  ofstream cout("brt.txt");
  ios_base::sync_with_stdio(0);cin.tie(0);
  _ncr();
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    memset(aa,-1,sizeof(aa));
    memset(rgt,-1,sizeof(rgt));
    for(int i=1;i<=n;i++)
      cin>>aa[i];
    sort(aa+1,aa+n+1);
    for(long i=n;i>=1;i--)
    {
      if(aa[i]==aa[i+1])rgt[i]=rgt[i+1];
      else rgt[i]=i;
    }
    long ans=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=0;j<=n;j++)
      {
        long a=ncr[i-1][j];
        long b=ncr[n-i][j];
        ans=(ans+a*b)%mod;
      }
      for(int j=0;j<=n;j++)
      {
        long a=ncr[i-1][j];
        long b=0,bb=0;
        for(int k=i+1;k<=rgt[i];k++)
        {
          b=(b+ncr[n-k][j])%mod;
          bb=(bb+qm[n-k][j]-qm[n-k-1][j]+mod)%mod;
        }
        //bb=(qm[n-(i+1)][j]-qm[n-(rgt[i]+1)][j]+mod+mod)%mod;
        if(b!=bb)assert(0);
        ans=(ans+a*b)%mod;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}