/****************************************************************************************
*  @author: kzvd4729                                         created: 27-02-2019 21:27:14                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 587.5M                               
*  problem: https://www.codechef.com/problems/CLMTRO
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
const long inf=1e18;
int aa[N+2],bb[N+2],sz[N+2];
long dp[N+2][3][N+2];
vector<int>adj[N+2];
bool cmp(int a,int b)
{
  return sz[a]>sz[b];
}
void dfs(int node,int par)
{
  sz[node]=1;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);sz[node]+=sz[x];
  }
  dp[node][0][0]=0;
  dp[node][0][1]=aa[node];
  dp[node][2][1]=bb[node];
  dp[node][1][0]=0;
  dp[node][2][0]=0;
  sort(adj[node].begin(),adj[node].end());
  int f=0;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(!f)
    {
      for(int i=sz[x]+1;i>=1;i--)
      {
        dp[node][0][i]=min(dp[node][0][i],dp[x][0][i]);
        dp[node][0][i]=min(dp[node][0][i],dp[x][0][i-1]+aa[node]);
        dp[node][0][i]=min(dp[node][0][i],dp[x][1][i]);
        dp[node][0][i]=min(dp[node][0][i],dp[x][1][i-1]+aa[node]);
        dp[node][1][i]=min(dp[node][1][i],dp[x][1][i-1]+bb[node]);
        dp[node][1][i]=min(dp[node][1][i],dp[x][2][i-1]+bb[node]);
        dp[node][2][i]=min(dp[node][2][i],dp[x][0][i-1]+bb[node]);
        dp[node][2][i]=min(dp[node][2][i],dp[x][1][i-1]+bb[node]);
        dp[node][2][i]=min(dp[node][2][i],dp[x][2][i-1]+bb[node]);
      }
      f=1;continue;
    }
    for(int i=sz[node];i>=1;i--)
    {
      for(int j=0;j<=min(i-1,sz[x]);j++)
      {
        dp[node][0][i]=min(dp[node][0][i],dp[x][0][j]+dp[node][0][i-j]);
        dp[node][0][i]=min(dp[node][0][i],dp[x][1][j]+dp[node][0][i-j]);
        dp[node][1][i]=min(dp[node][1][i],dp[x][1][j]+dp[node][1][i-j-1]+bb[i]);
        dp[node][1][i]=min(dp[node][1][i],dp[x][2][j]+dp[node][1][i-j-1]+bb[i]);
        dp[node][2][i]=min(dp[node][2][i],dp[x][0][j]+dp[node][2][i-j-1]+bb[i]);
        dp[node][2][i]=min(dp[node][2][i],dp[x][1][j]+dp[node][2][i-j-1]+bb[i]);
        dp[node][2][i]=min(dp[node][2][i],dp[x][2][j]+dp[node][2][i-j-1]+bb[i]);
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  //dont complie
  int t;cin>>t;
  while(t--)
  {
    int n;long k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>aa[i];
    for(int i=1;i<=n;i++)cin>>bb[i];
    for(int i=1;i<=n;i++)
      adj[i].clear();
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for(int i=0;i<=n;i++)
      for(int j=0;j<3;j++)
        for(int l=0;l<=n;l++)
          dp[i][j][l]=inf;
    dfs(1,-1);int ans=0;
    for(int i=1;i<=n;i++)
    {
      if(min(dp[1][0][i],dp[1][1][i])<=k)
        ans=i;
    }
    int x=1;
    for(int i=1;i<=n;i++)
    {
      cout<<dp[x][0][i]<<" "<<dp[x][1][i]<<" "<<dp[x][2][i]<<endl;
    }
    cout<<ans<<endl;
  }
  return 0;
}