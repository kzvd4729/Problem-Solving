/****************************************************************************************
*  @author: kzvd4729                                         created: 07-04-2019 22:25:56                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 1.00 sec                                        memory_used: 61.5M                                
*  problem: https://www.codechef.com/ALKH2019/problems/CERSOL
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,M=(1<<10),inf=1e6;
int cls[N+2],dp[2500+2][2][M+2];
vector<int>adj[N+2],sub[M+2];
int norm(int msk,int bt)
{
  if((msk&(1<<bt)))
    return (msk^(1<<bt));
  return msk;
}
int dfs(int node,int f,int msk)
{
  if(adj[node].size()==0)
  {
    if(msk)return inf;
    return 0;
  }
  if(dp[node][f][msk]!=-1)return dp[node][f][msk];
  int ret=inf;
  if(adj[node].size()==1)
  {
    int nx=adj[node][0];
    ret=min(ret,1+dfs(nx,1,norm(msk,cls[nx]-1)));
    if(f)ret=min(ret,dfs(nx,0,msk));
  }
  else
  {
    int nx1=adj[node][0],nx2=adj[node][1];
    for(auto x:sub[msk])
    {
      if(f)
      {
        ret=min(ret,1+dfs(nx1,1,norm(x,cls[nx1]-1))+1+dfs(nx2,1,norm((msk^x
            ),cls[nx2]-1)));
        ret=min(ret,1+dfs(nx1,1,norm(x,cls[nx1]-1))+dfs(nx2,0,(msk^x)));
        ret=min(ret,dfs(nx1,0,x)+1+dfs(nx2,1,norm((msk^x),cls[nx2]-1)));
        ret=min(ret,dfs(nx1,0,x)+dfs(nx2,0,(msk^x)));
      }
      else
      {
        ret=min(ret,1+dfs(nx1,1,norm(x,cls[nx1]-1))+1+dfs(nx2,1,norm((msk^x
            ),cls[nx2]-1)));
      }
    }
  }
  return dp[node][f][msk]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=1;i<M;i++)
  {
    for(int j=0;j<=i;j++)
    {
      if((i&j)==j)
        sub[i].push_back(j);
    }
  }
  int t;cin>>t;
  while(t--)
  {
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
      memset(dp[i],-1,sizeof(dp[i]));
    for(int i=1;i<=n;i++)
      cin>>cls[i];
    for(int i=1;i<=n;i++)
      adj[i].clear();
    while(m--)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);
    }
    int msk=(1<<k)-1;int ret=inf;
    ret=min(ret,1+dfs(1,1,norm(msk,cls[1]-1)));
    ret=min(ret,dfs(1,0,msk));
    if(ret==inf)ret=-1;
    cout<<ret<<"\n";
  }
  return 0;
}