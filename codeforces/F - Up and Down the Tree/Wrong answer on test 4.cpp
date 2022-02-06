/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/11/2019 14:52                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 105700 KB                            
*  problem: https://codeforces.com/contest/1065/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int sp[N+2][22],cnt[N+2],ans,dp[N+2];
vector<int>adj[N+2];
void build(int n)
{
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if(sp[i][j]!=-1)
        sp[i][j]=sp[sp[i][j]][j-1];
    }
  }
}
int raise(int u,int k)
{
  for(int i=20;i>=0;i--)
  {
    if((1<<i)>k)continue;
    u=sp[u][i];k-=(1<<i);
    if(u==-1)return -1;
  }
  return u;
}
void dfs(int node)
{
  for(auto x:adj[node])
  {
    dfs(x);cnt[node]+=cnt[x];
    dp[node]+=dp[x];
  }
}
void dds(int node,int now)
{
  ans=max(ans,now+cnt[node]);
  for(auto x:adj[node])
    now+=dp[x];
  for(auto x:adj[node])
    dds(x,now-dp[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;sp[1][0]=-1;
  for(int i=2;i<=n;i++)
  {
    int x;cin>>x;adj[x].push_back(i);
    sp[i][0]=x;
  }
  build(n);
  for(int i=1;i<=n;i++)
  {
    if(adj[i].size())continue;
    cnt[i]++;dp[i]++;
    int p=raise(i,k);
    //cout<<i<<" --> "<<p<<endl;
    if(p!=-1)
    {
      dp[p]--;p=sp[p][0];
      if(p!=-1)cnt[p]--;
    }
  }
  dfs(1);
  /*for(int i=1;i<=n;i++)
    cout<<cnt[i]<<" ";
  cout<<endl;
  for(int i=1;i<=n;i++)
    cout<<dp[i]<<" ";
  cout<<endl;*/
   dds(1,0);cout<<ans<<endl;
   return 0;
}