/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/19/2018 23:00                        
*  solution_verdict: Time limit exceeded on test 3           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 20600 KB                             
*  problem: https://codeforces.com/gym/100570/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,q,tot,sz[N+2],mark[N+2],anc[N+2];
int dist[N+2][22],lev[N+2];
vector<pair<int,int> >adj[N+2];
vector<int>own[N+2],con[N+2];
void dfs(int node,int par)
{
  tot++;sz[node]=1;
  for(auto x:adj[node])
  {
    if(x.first==par||mark[x.first])continue;
    dfs(x.first,node);sz[node]+=sz[x.first];
  }
}
int find_center(int node,int par)
{
  for(auto x:adj[node])
  {
    if(x.first==par||mark[x.first])continue;
    if(sz[x.first]>tot/2)return find_center(x.first,node);
  }
  return node;
}
void cal_dist(int center,int lv,int node,int par,int ds)
{
  dist[node][lv]=ds;own[center].push_back(ds);
  if(anc[center]!=-1)con[center].push_back(dist[node][lev[anc[center]]]);
  for(auto x:adj[node])
  {
    if(x.first==par||mark[x.first])continue;
    cal_dist(center,lv,x.first,node,ds+x.second);
  }
}
void centroid(int node,int par,int lv)
{
  tot=0;dfs(node,-1);
  int center=find_center(node,-1);
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
  for(int i=1;i<n;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});adj[v].push_back({u,w});
  }
  centroid(1,-1,1);
  while(q--)
  {
    int nd,l,ans=0,tmp;cin>>nd>>l;
    while(true)
    {
      ans+=upper_bound(own[nd].begin(),own[nd].end(),l)-own[nd].begin();
      tmp=nd;nd=anc[tmp];if(nd==-1)break;l-=dist[tmp][lev[nd]];
      ans-=upper_bound(con[tmp].begin(),con[tmp].end(),l)-con[tmp].begin();
    }
    cout<<ans<<"\n";
  }
  return 0;
}