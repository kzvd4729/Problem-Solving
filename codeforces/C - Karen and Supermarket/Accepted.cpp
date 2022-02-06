/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/27/2019 17:52                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 405 ms                                          memory_used: 392500 KB                            
*  problem: https://codeforces.com/contest/815/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
const long inf=1e18;
int pr[N+2],ds[N+2],sz[N+2];
long dp[N+2][2][N+2];
vector<int>adj[N+2];
bool cmp(int a,int b)
{
  return sz[a]>sz[b];
}
void dfs(int node)
{
  sz[node]=1;
  for(auto x:adj[node])
  {
    dfs(x);sz[node]+=sz[x];
  }
  dp[node][1][1]=pr[node]-ds[node];
  dp[node][0][1]=pr[node];
  dp[node][0][0]=0;int f=0;
  sort(adj[node].begin(),adj[node].end(),cmp);
  for(auto x:adj[node])
  {
    if(!f)
    {
      for(int i=sz[x]+1;i>=0;i--)
      {
        dp[node][1][i]=min(dp[x][1][i-1],dp[x][0][i-1])+dp[node][1][1];
        dp[node][0][i]=min(dp[x][0][i],dp[x][0][i-1]+dp[node][0][1]);
      }
      f=1;continue;
    }
    for(int i=sz[node];i>=0;i--)
    {
      for(int j=0;j<=min(sz[x],i);j++)
      {
        dp[node][1][i]=min(dp[node][1][i],dp[x][1][j]+dp[node][1][i-j]);
        dp[node][1][i]=min(dp[node][1][i],dp[x][0][j]+dp[node][1][i-j]);
        dp[node][0][i]=min(dp[node][0][i],dp[x][0][j]+dp[node][0][i-j]);
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,b;cin>>n>>b;cin>>pr[1]>>ds[1];
  for(int i=2;i<=n;i++)
  {
    int x;cin>>pr[i]>>ds[i]>>x;
    adj[x].push_back(i);
  }
  memset(dp,0x3F3F3F3F,sizeof(dp));
  dfs(1);long mx=0;int ans=0;
  for(int i=1;i<=n;i++)
  {
    mx=max(mx,min(dp[1][0][i],dp[1][1][i]));
    if(mx<=b)ans=i;
  }
  cout<<ans<<endl;
  return 0;
}