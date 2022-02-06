/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/17/2018 16:56                        
*  solution_verdict: Wrong answer on test 25                 language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 5500 KB                              
*  problem: https://codeforces.com/contest/600/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int cl[N+2],n,u,v,maxx,sum,ans[N+2];
int sz[N+2],bad[N+2],cnt[N+2];
vector<int>adj[N+2];
void siz(int node,int par)
{
  sz[node]=1;
  for(auto next:adj[node])
  {
    if(next==par)continue;
    siz(next,node);
    sz[node]+=sz[next];
  }
}
void reval(int x)
{
  if(maxx<++cnt[x])
    maxx=cnt[x],sum=x;
  else if(maxx==cnt[x])
    sum+=x;
}
void add(int node,int par)
{
  reval(cl[node]);
  for(auto next:adj[node])
  {
    if(next==par||bad[next])continue;
    add(next,node);
  }
}
void rem(int node,int par)
{
  cnt[cl[node]]--;
  for(auto next:adj[node])
  {
    if(next==par||bad[next])continue;
    rem(next,node);
  }
}
void dfs(int node,int par,int ckr)
{
  int mx=-1,big=-1;
  for(auto next:adj[node])
  {
    if(next==par)continue;
    if(sz[next]>mx)
      mx=sz[next],big=next;
  }
  for(auto next:adj[node])
  {
    if(next==par||next==big)continue;
    dfs(next,node,1);
  }
  if(big!=-1)
    dfs(big,node,0),bad[big]=1;
  add(node,par);
  if(big!=-1)
    bad[big]=0;
  ans[node]=sum;
  if(ckr)
    rem(node,par),maxx=sum=0;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>cl[i];
  for(int i=1;i<n;i++)
  {
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  siz(1,-1);
  dfs(1,-1,0);
  for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}