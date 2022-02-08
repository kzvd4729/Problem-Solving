/****************************************************************************************
*  @author: kzvd4729                                         created: 02-11-2018 23:46:34                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.09 sec                                        memory_used: 76.1M                                
*  problem: https://www.codechef.com/NOV18A/problems/GMEDIAN
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;
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
      for(int k=i+1;k<=rgt[i];k++)
      {
        for(int j=0;j<=n;j++)
        {
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