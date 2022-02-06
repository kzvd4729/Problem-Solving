/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/28/2018 15:24                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 19300 KB                             
*  problem: https://codeforces.com/contest/208/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,x,tim,st[N+2],ed[N+2],fr[N+2];
int lin[N+2],hg[N+2],sz[N+2],ans[N+2];
int sp[20][N+2];
vector<int>adj[N+2],rt;
vector<pair<int,int> >qu[N+2];
void reckon(int node,int h)
{
  ++tim;
  lin[tim]=node;
  st[node]=tim;
  hg[node]=h;
  sz[node]=1;
  for(auto x:adj[node])
  {
    reckon(x,h+1);
    sz[node]+=sz[x];
  }
  ed[node]=tim;
}
void dfs(int node,int clr)
{
  int mx=-1,spc=-1;
  for(auto x:adj[node])
    if(sz[x]>mx)
      mx=sz[x],spc=x;
  for(auto x:adj[node])
    if(x!=spc)
      dfs(x,1);
  if(spc!=-1)dfs(spc,0);
  for(auto x:adj[node])
  {
    if(x==spc)continue;
    for(int i=st[x];i<=ed[x];i++)
      fr[hg[lin[i]]]++;
  }
  fr[hg[node]]++;
   for(auto xx:qu[node])
    ans[xx.second]=fr[hg[node]+xx.first]-1;
  if(clr)
  {
    for(int i=st[node];i<=ed[node];i++)
      fr[hg[lin[i]]]--;
  }
}
void build(void)
{
  for(int j=1;j<=18;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if(sp[j-1][i]==-1)continue;
      sp[j][i]=sp[j-1][sp[j-1][i]];
    }
  }
}
int raise(int node,int xx)
{
  for(int j=18;j>=0;j--)
  {
    if((1<<j)<=xx)
    {
      node=sp[j][node];
      xx-=(1<<j);
    }
  }
  return node;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  memset(sp,-1,sizeof(sp));
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    if(x)
    {
      adj[x].push_back(i);
      sp[0][i]=x;
    }
    else rt.push_back(i);
  }
  build();
  for(auto x:rt)
    reckon(x,1);
  int q;cin>>q;
  for(int i=1;i<=q;i++)
  {
    int vi,pi;cin>>vi>>pi;
    qu[raise(vi,pi)].push_back({pi,i});
  }
  for(auto x:rt)
    dfs(x,1);
  for(int i=1;i<=q;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}