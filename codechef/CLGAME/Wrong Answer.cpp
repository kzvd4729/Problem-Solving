/****************************************************************************************
*  @author: kzvd4729                                         created: 27-02-2019 18:43:29                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.02 sec                                        memory_used: 37.8M                                
*  problem: https://www.codechef.com/problems/CLGAME
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,k,id,aa[N+2],bb[N+2];
int vis[N+2][2],dp[N+2][2];
int dfs(int i,int mv)
{
  if(i==n)return 0;
  if(vis[i][mv])return dp[i][mv];
  int now=0;vis[i][mv]=1;
  for(int j=1;j<=k;j++)
  {
    if(i+bb[j]>n)continue;
    if(!mv)
    {
      if(i<=id&&i+bb[j]<=id)
        now=max(now,1+dfs(i+bb[j],mv^1));
      else now=max(now,dfs(i+bb[j],mv^1));
    }
    else
    {
      now=min(now,dfs(i+bb[j],mv^1));
    }
  }
  return dp[i][mv]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>k;int mx=-1;
    for(int i=1;i<=n;i++)
    {
      cin>>aa[i];if(aa[i]>mx)mx=aa[i],id=i;
    }
    for(int i=1;i<=k;i++)cin>>bb[i];
    for(int i=0;i<=n+1;i++)
      vis[i][0]=0,vis[i][1]=0;
    if(dfs(1,0))cout<<"Chef\n";
    else cout<<"Garry\n";
  }
  return 0;
}