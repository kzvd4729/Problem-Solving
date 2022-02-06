/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/30/2018 15:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1107 ms                                         memory_used: 72000 KB                             
*  problem: https://codeforces.com/contest/570/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
int dep[N+2],ent[N+2],ext[N+2],tim,sz[N+2];
int sack[N+2],lin[N+2],ans[N+2];
vector<int>adj[N+2];
vector<pair<int,int> >qu[N+2];
string s;
int cn(int node){return (int)(s[node-1]-'a');}
void dfs(int node,int dp)
{
  dep[node]=dp;ent[node]=++tim;
  sz[node]=1;lin[tim]=node;
  for(auto x:adj[node])
    dfs(x,dp+1),sz[node]+=sz[x];
  ext[node]=tim;
}
void dsu(int node,int clr)
{
  int mx=-1,spc=-1;
  for(auto x:adj[node])
    if(sz[x]>mx)mx=sz[x],spc=x;
  for(auto x:adj[node])
    if(x!=spc)dsu(x,1);
  if(spc!=-1)dsu(spc,0);
   sack[dep[node]]^=(1<<cn(node));
  for(auto x:adj[node])
  {
    if(x==spc)continue;
    for(int i=ent[x];i<=ext[x];i++)
    {
      int nd=lin[i];
      sack[dep[nd]]^=(1<<cn(nd));
    }
  }
  for(auto x:qu[node])
  {
    int h=x.first;
    if(__builtin_popcount(sack[h])<=1)ans[x.second]=1;
  }
  if(clr)
  {
    for(int i=ent[node];i<=ext[node];i++)
    {
      int nd=lin[i];
      sack[dep[nd]]^=(1<<cn(nd));
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=2;i<=n;i++)
  {
    int x;cin>>x;
    adj[x].push_back(i);
  }
  cin>>s;
  for(int i=1;i<=m;i++)
  {
    int x,h;cin>>x>>h;
    qu[x].push_back({h,i});
  }
  dfs(1,1);dsu(1,0);
  for(int i=1;i<=m;i++)
  {
    if(ans[i])cout<<"Yes\n";
    else cout<<"No\n"<<endl;
  }
  return 0;
}