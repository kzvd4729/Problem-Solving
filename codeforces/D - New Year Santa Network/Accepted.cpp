/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/22/2018 10:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 779 ms                                          memory_used: 21700 KB                             
*  problem: https://codeforces.com/contest/500/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int>adj[N+2];
long long n,sz[N+2],cs[N+2],hw[N+2];
long double tt,dn;
map<pair<int,int>,int>mp;
void dfs(int node,int par)
{
 sz[node]=1LL;
 for(int i=0;i<adj[node].size();i++)
 {
  int xx=adj[node][i];
  if(xx==par)continue;
  dfs(xx,node);sz[node]+=sz[xx];
 }
}
void dds(int node,int par)
{
 for(int i=0;i<adj[node].size();i++)
 {
  int xx=adj[node][i];
  if(xx==par)continue;
  int nn=mp[make_pair(node,xx)];
  hw[nn]=(sz[1]-sz[xx])*(sz[1]-sz[xx]-1)*sz[xx];
  hw[nn]+=(sz[xx]*(sz[xx]-1)*(sz[1]-sz[xx]));
  dds(xx,node);
 }
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 cin>>n;
 for(int i=1;i<n;i++)
 {
  int u,v,w;cin>>u>>v>>w;
  adj[u].push_back(v);
  adj[v].push_back(u);
  mp[make_pair(u,v)]=i;mp[make_pair(v,u)]=i;
  cs[i]=w;
 }
 dfs(1,-1);dds(1,-1);
  for(int i=1;i<n;i++)
  tt+=(cs[i]*hw[i]*1.0);
 dn=(n*(n-1)*(n-2)/6)*1.0;
  int q;cin>>q;
 while(q--)
 {
  int id,w;cin>>id>>w;
  tt-=(cs[id]*hw[id]*1.0);cs[id]=w;
  tt+=(cs[id]*hw[id]*1.0);
  long double pr=tt/dn;
  cout<<setprecision(10)<<fixed<<pr<<endl;
 }
 return 0;
}