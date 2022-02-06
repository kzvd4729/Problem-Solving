/****************************************************************************************
*  @author: kzvd4729                                         created: May/17/2018 19:30                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++11                               
*  run_time: 93 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/479/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
int n,a,b,k,d;
long dp[5005],qm[5005];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>a>>b>>k;
   int d=abs(a-b)-1;
  for(int i=a+1;i<=min(n,a+d);i++)dp[i]=1;
  for(int i=a-1;i>=max(1,a-d);i--)dp[i]=1;
//  for(int j=1;j<=n;j++)
//      cout<<dp[j]<<" ";
//    cout<<endl;
  for(int j=1;j<=n;j++)
      qm[j]=(dp[j]+qm[j-1])%mod;
  for(int i=2;i<=k;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(j==b)continue;
      int f=0;
      d=b-j;
      if(d<0)f=1;
      d=abs(d)-1;
       if(f)
        dp[j]=qm[n]-qm[j-d/2-1]-qm[j]+qm[j-1];
      else dp[j]=qm[j+d/2]-qm[j]+qm[j-1];
        //dp[j]=(qm[min(n,j+d)]-qm[j]-qm[max(1,j-d)]+qm[j]+mod+mod)%mod;
    }
//    for(int j=1;j<=n;j++)
//      cout<<dp[j]<<" ";
//    cout<<endl;
    for(int j=1;j<=n;j++)
      qm[j]=(dp[j]+qm[j-1])%mod;
    memset(dp,0,sizeof(dp));
  }
  cout<<qm[n]<<endl;
  return 0;
}