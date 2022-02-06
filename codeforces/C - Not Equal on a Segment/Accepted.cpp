/****************************************************************************************
*  @author: kzvd4729#                                        created: Oct/29/2018 23:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/622/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  dp[n]=n;
  for(int i=n-1;i>=1;i--)
  {
    if(aa[i]==aa[i+1])dp[i]=dp[i+1];
    else dp[i]=i;
  }
  while(m--)
  {
    int l,r,x;cin>>l>>r>>x;
    if(aa[l]!=x)
    {
      cout<<l<<"\n";
    }
    else
    {
      if(dp[l]+1>r)cout<<-1<<"\n";
      else cout<<dp[l]+1<<"\n";
    }
  }
  return 0;
}