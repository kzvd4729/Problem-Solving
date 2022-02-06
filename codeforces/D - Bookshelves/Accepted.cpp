/****************************************************************************************
*  @author: kzvd4729                                         created: May/27/2018 22:32                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/981/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,arr[52],qm[52],ans,tmp,dp[52][52];
long sum;
bool ok(long sm,long msk)
{
  long xx=sm&msk;
  if(xx==msk)return true;
  return false;
}
bool possible(long msk)
{
  memset(dp,0,sizeof(dp));
  dp[0][0]=1;
  for(int kk=1;kk<=k;kk++)
  {
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=i;j++)
      {
        sum=qm[i]-qm[j-1];
        if(!dp[j-1][kk-1])continue;
        if(ok(sum,msk))dp[i][kk]=1;
      }
    }
  }
  return dp[n][k];
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    qm[i]=qm[i-1]+arr[i];
  }
  for(long i=60;i>=0;i--)
  {
    tmp=ans|(1LL<<i);
    if(possible(tmp))
      ans=tmp;
  }
  cout<<ans<<endl;
  return 0;
}