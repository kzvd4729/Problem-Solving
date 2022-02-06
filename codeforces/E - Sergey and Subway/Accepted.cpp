/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/04/2018 15:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 701 ms                                          memory_used: 22900 KB                             
*  problem: https://codeforces.com/contest/1060/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
long n,tot,sz[N+2],mark[N+2],ans,cod,cev,codsm,cevsm;
long odd,even,oddsm,evensm;
vector<long>adj[N+2];
void dfs(long node,long par)
{
  tot++;sz[node]=1;
  for(auto x:adj[node])
  {
    if(mark[x]||x==par)continue;
    dfs(x,node);sz[node]+=sz[x];
  }
}
long find_center(long node,long par)
{
  for(auto x:adj[node])
  {
    if(mark[x]||x==par)continue;
    if(sz[x]>tot/2)return find_center(x,node);
  }
  return node;
}
void _cal(long node,long par,long ds)
{
  ans+=(ds+1)/2;
  if(ds%2==0)
  {
    ans+=even*(ds/2)+evensm/2;
    ans+=odd*(ds/2)+(oddsm+odd)/2;
    cev++;cevsm+=ds;
  }
  else
  {
    ans+=even*(ds+1)/2+evensm/2;
    ans+=(oddsm+odd*ds)/2;
    cod++;codsm+=ds;
  }
  for(auto x:adj[node])
  {
    if(x==par||mark[x])continue;
    _cal(x,node,ds+1);
  }
}
void centroid(long node,long par)
{
  tot=0;dfs(node,-1);
  long center=find_center(node,-1);
  mark[center]=1;
    odd=0,even=0,oddsm=0,evensm=0;
  for(auto x:adj[center])
  {
    if(mark[x])continue;
    cod=0,cev=0,codsm=0,cevsm=0;
    _cal(x,-1,1);
    odd+=cod;oddsm+=codsm;
    evensm+=cevsm;even+=cev;
   }
  for(auto x:adj[center])
  {
    if(mark[x])continue;
    centroid(x,center);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(long i=1;i<n;i++)
  {
    long u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  centroid(1,-1);cout<<ans<<endl;
   return 0;
}