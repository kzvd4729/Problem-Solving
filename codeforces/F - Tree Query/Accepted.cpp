/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/20/2018 00:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 514 ms                                          memory_used: 50200 KB                             
*  problem: https://codeforces.com/gym/100570/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long n,q,tot,sz[N+2],mark[N+2],anc[N+2];
long dist[N+2][22],lev[N+2];
vector<pair<long,long> >adj[N+2];
vector<long>own[N+2],con[N+2];
void dfs(long node,long par)
{
  tot++;sz[node]=1;
  for(auto x:adj[node])
  {
    if(x.first==par||mark[x.first])continue;
    dfs(x.first,node);sz[node]+=sz[x.first];
  }
}
long find_center(long node,long par)
{
  for(auto x:adj[node])
  {
    if(x.first==par||mark[x.first])continue;
    if(sz[x.first]>tot/2)return find_center(x.first,node);
  }
  return node;
}
void cal_dist(long center,long lv,long node,long par,long ds)
{
  dist[node][lv]=ds;own[center].push_back(ds);
  if(anc[center]!=-1)con[center].push_back(dist[node][lev[anc[center]]]);
  for(auto x:adj[node])
  {
    if(x.first==par||mark[x.first])continue;
    cal_dist(center,lv,x.first,node,ds+x.second);
  }
}
void centroid(long node,long par,long lv)
{
  tot=0;dfs(node,-1);
  long center=find_center(node,-1);
  mark[center]=1;anc[center]=par;lev[center]=lv;
  cal_dist(center,lv,center,-1,0);
  sort(own[center].begin(),own[center].end());
  sort(con[center].begin(),con[center].end());
  for(auto x:adj[center])
  {
    if(mark[x.first])continue;
    centroid(x.first,center,lv+1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>q;
  for(long i=1;i<n;i++)
  {
    long u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});adj[v].push_back({u,w});
  }
  centroid(1,-1,1);
  while(q--)
  {
    long nd,l,ll,ans=0,tmp,bs;cin>>nd>>l;ll=l,bs=nd;
    while(true)
    {
      ans+=upper_bound(own[nd].begin(),own[nd].end(),l)-own[nd].begin();
      tmp=nd;nd=anc[nd];if(nd==-1)break;l=ll-dist[bs][lev[nd]];
      ans-=upper_bound(con[tmp].begin(),con[tmp].end(),l)-con[tmp].begin();
    }
    cout<<ans<<"\n";
  }
  return 0;
}