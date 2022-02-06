/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/24/2020 20:52                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/633/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2],dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>aa[i],aa[i]*=100;
  for(int i=1;i<=n;i++)cin>>bb[i];
   dp[n]=min(aa[n],bb[n]);
  for(int i=n-1;i>=1;i--)
    dp[i]=max(min(aa[i],bb[i]),min(bb[i],dp[i+1]));
  sort(dp+1,dp+n+1);
  //for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
    //cout<<endl;
  double ans=0,p=1.0;
  for(int i=1;i<=m;i++)p*=i;
  for(int i=1;i<=(n-m);i++)p*=i;
  for(int i=1;i<=n;i++)p/=i;
  ans+=dp[n-m+1]*p;
  for(int i=n-m;i>=1;i--)
  {
    p*=(n-i);p/=(i-(n-m)+1);
    ans+=dp[i]*p;
  }
  cout<<ans<<endl;
  return 0;
}