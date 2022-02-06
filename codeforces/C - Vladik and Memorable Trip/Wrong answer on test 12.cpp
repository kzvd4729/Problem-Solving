/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/26/2018 22:01                        
*  solution_verdict: Wrong answer on test 12                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/811/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int arr[5005],dp[5005],xr,n,vis[5005],x,first[5005],last[5005];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>x,arr[i]=x;
    if(!first[x])first[x]=i;
    last[x]=i;
  }
  for(int i=1;i<=n;i++)
  {
    x=arr[i];
    dp[i]=dp[i-1];
    if(last[x]!=i)continue;
    memset(vis,0,sizeof(vis));
    int xr=0;
    for(int j=first[x];j<=last[x];j++)
    {
      if(vis[arr[j]])continue;
      vis[arr[j]]=1;
      xr=xr^arr[j];
    }
    dp[i]=max(dp[i],xr+dp[first[x]-1]);
  }
  cout<<dp[n]<<endl;
  return 0;
}