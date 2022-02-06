/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/16/2018 21:25                        
*  solution_verdict: Wrong answer on test 18                 language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1081/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int par[N+2];
struct edge
{
  int u,v,w;
}ed[N+2];
bool cmp(edge A,edge B)
{
  return A.w<B.w;
}
int _find(int x)
{
  if(x==par[x])return x;
  return par[x]=_find(par[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=k;i++)
  {
    int x;cin>>x;
  }
  for(int i=1;i<=m;i++)
    cin>>ed[i].u>>ed[i].v>>ed[i].w;
  sort(ed+1,ed+m+1,cmp);
  for(int i=1;i<=n;i++)par[i]=i;
  int ans=0;
  for(int i=1;i<=m;i++)
  {
    int r1=_find(ed[i].u);
    int r2=_find(ed[i].v);
     if(r1==r2)continue;
     ans=max(ans,ed[i].w);
    par[r2]=r1;
  }
  while(k--)
    cout<<ans<<" ";
  cout<<endl;
  return 0;
}