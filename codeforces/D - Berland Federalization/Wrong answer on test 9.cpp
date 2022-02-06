/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/30/2019 23:23                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 1700 KB                              
*  problem: https://codeforces.com/contest/440/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=4e2,inf=1e9;
int n,k,dp[N+2][N+2],tmp[N+2][N+2],parent[N+2];
vector<int>adj[N+2],nex[N+2];
vector<pair<int,int> >ed;
map<pair<int,int>,int>mp;
void dfs(int node,int par)
{
  parent[node]=par;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);nex[node].push_back(x);
  }
  if(nex[node].size()==0)
  {
    dp[node][1]=0;return ;
  }
  int x=nex[node][0];dp[node][1]=1;
  for(int i=2;i<=k;i++)
    dp[node][i]=dp[x][i-1];
  for(int l=1;l<nex[node].size();l++)
  {
    x=nex[node][l];
    for(int i=k;i>=1;i--)
    {
      dp[node][i]++;
      for(int j=1;j<i;j++)
        dp[node][i]=min(dp[node][i],dp[x][j]+dp[node][i-j]);
    }
  }
}
void print(int node,int k)
{
  int sz=nex[node].size();
  if(!sz)return ;
  for(int i=0;i<sz;i++)
    for(int j=1;j<=k;j++)
      tmp[i][j]=inf;
   int x=nex[node][0];tmp[0][1]=1;
  for(int i=2;i<=k;i++)
    tmp[0][i]=dp[x][i-1];
  for(int l=1;l<sz;l++)
  {
    x=nex[node][l];
    for(int i=k;i>=1;i--)
    {
      tmp[l][i]=tmp[l-1][i]+1;
      for(int j=1;j<i;j++)
        tmp[l][i]=min(tmp[l][i],dp[x][j]+tmp[l-1][i-j]);
    }
  }
  for(int l=sz-1;l>=1;l--)
  {
    int x=nex[node][l];
    if(tmp[l-1][k]+1==tmp[l][k])
    {
      ed.push_back({node,x});
      continue;
    }
    for(int i=1;i<k;i++)
    {
      if(tmp[l-1][k-i]+dp[x][i]==tmp[l][k])
      {
        print(x,i);k-=i;break;
      }
    }
  }
  if(k==1)ed.push_back({node,nex[node][0]});
  else print(nex[node][0],k-1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    mp[{u,v}]=mp[{v,u}]=i;
  }
  for(int i=1;i<=n;i++)
    for(int j=1;j<=k;j++)
      dp[i][j]=inf;
  dfs(1,-1);int mn=dp[1][k];int rt=1;
  for(int i=2;i<=n;i++)
  {
    if(dp[i][k]+1<mn)
      mn=dp[i][k]+1,rt=i;
  }
  if(rt!=1)ed.push_back({rt,parent[rt]});
  print(rt,k);cout<<mn<<endl;
  for(auto x:ed)cout<<mp[{x.first,x.second}]<<" ";
    cout<<endl;
  return 0;
}