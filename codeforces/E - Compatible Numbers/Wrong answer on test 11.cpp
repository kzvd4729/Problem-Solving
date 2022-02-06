/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/31/2019 16:21                        
*  solution_verdict: Wrong answer on test 11                 language: GNU C++14                               
*  run_time: 186 ms                                          memory_used: 65700 KB                             
*  problem: https://codeforces.com/contest/165/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=(1<<22);
int dp[N+2],pr[N+2],fr[N+2],aa[N+2];
void sos(int n)
{
  for(int i=0;i<(1<<n);i++)
  {
    dp[i]=fr[i];
    if(dp[i])pr[i]=i;
  }
  for(int i=0;i<n;i++)
  {
    for(int msk=0;msk<(1<<n);msk++)
    {
      if(msk&(1<<i))
      {
        int nms=msk^(1<<i);
        dp[msk]|=dp[nms];
        if(dp[nms])pr[msk]=pr[nms];
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];fr[aa[i]]=1;
  }
  sos(22);
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<20;j++)
      aa[i]^=(1<<j);
    if(!dp[aa[i]])cout<<-1<<" ";
    else cout<<pr[aa[i]]<<" ";
  }
  cout<<"\n";
   return 0;
}