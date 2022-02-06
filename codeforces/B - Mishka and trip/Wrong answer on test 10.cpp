/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/23/2018 19:49                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 5200 KB                              
*  problem: https://codeforces.com/contest/703/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int bt[100005],cp[100005],n,k,ans,cpp[100005],vis[100005],sum[100005];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>bt[i];
  for(int i=n;i>=1;i--)sum[i]=sum[i+1]+bt[i];
  for(int i=1;i<=k;i++)cin>>cp[i],vis[cp[i]]=1;
  for(int i=n;i>=1;i--)
  {
    cpp[i]=cpp[i+1];
    if(vis[i])cpp[i]+=bt[i];
  }
  for(int i=1;i<=n;i++)
  {
    if(vis[i])ans+=bt[i]*sum[i+1];
    else
    {
      ans+=cpp[i+1]*bt[i];
      if(!vis[i+1])ans+=bt[i]*bt[i+1];
      if(i==1)if(!vis[n])ans+=bt[1]*bt[n];
    }
  }
  cout<<ans<<endl;
  return 0;
}