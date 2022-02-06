/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/23/2019 16:24                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1123 ms                                         memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/1249/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e2;
int k,vl[N+2],dp[N+2][N+2];
vector<int>adj[N+2];
int dfs(int node,int par,int d)
{
  if(dp[node][d]!=-1)return dp[node][d];
  int now=0;
  if(!d)
  {
    for(auto x:adj[node])
      if(x!=par)now+=dfs(x,node,k);
    now+=vl[node];
  }
  vector<vector<int> >ad,qm;
  ad.resize(k+1),qm.resize(k+1);
  for(int i=0;i<=k;i++)
  {
    ad[i].resize((int)adj[node].size()+1);
    qm[i].resize((int)adj[node].size()+1);
  }
  int id=0;
  for(auto x:adj[node])
  {
    if(x==par)continue;id++;
    for(int i=0;i<=k;i++)
    {
      ad[i][id]=dfs(x,node,i);
    }
  }
  for(int i=0;i<=k;i++)
    for(int j=1;j<=id;j++)qm[i][j]=qm[i][j-1]+ad[i][j];
  for(int i=1;i<=id;i++)
  {
    for(int j=k;j>=max(0,d-1);j--)
    {
      int l=max(0,max(d-1,max(j,k-1-j)));
      now=max(now,ad[j][i]+qm[l][id]-ad[l][i]);
    }
  }
  return dp[node][d]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n>>k;
   for(int i=1;i<=n;i++)cin>>vl[i];
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,0,0)<<endl;
   return 0;
}