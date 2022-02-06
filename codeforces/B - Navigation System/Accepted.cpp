/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/01/2020 19:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 37800 KB                             
*  problem: https://codeforces.com/contest/1320/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int p[N+2],n,ds[N+2];
vector<int>adj[N+2],fr[N+2];
void bfs(int node)
{
 for(int i=1;i<=n;i++)ds[i]=inf;
 queue<int>q;q.push(node);ds[node]=0;
  while(q.size())
 {
  int u=q.front();q.pop();
  for(auto x:adj[u])
  {
   if(ds[u]+1<ds[x])
   {
    ds[x]=ds[u]+1;q.push(x);
   }
  }
 }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
   int u,v;cin>>u>>v;
   adj[v].push_back(u);fr[u].push_back(v);
  }
  int k;cin>>k;for(int i=1;i<=k;i++)cin>>p[i];
  bfs(p[k]);int mn=0,mx=0,d=ds[1];//cout<<d<<endl;
  //for(int i=1;i<=n;i++)cout<<ds[i]<<" ";
   //cout<<endl;
  for(int i=1;i<k;i++)
  {
   if(ds[p[i]]-1!=ds[p[i+1]])mn++;
    int f=0;
   for(auto x:fr[p[i]])
   {
    if(x==p[i+1])continue;
    if(ds[p[i]]-1==ds[x])f=1;
   }
   mx+=f;
  }
  cout<<mn<<" "<<mx<<endl;
  return 0;
}