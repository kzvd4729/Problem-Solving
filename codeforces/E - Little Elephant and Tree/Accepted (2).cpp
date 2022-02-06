/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/23/2019 21:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 810 ms                                          memory_used: 15900 KB                             
*  problem: https://codeforces.com/contest/258/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=1e9;
 struct segment
{
  int cnt,sm,dsm;
}seg[5*N+2];
void mrge(segment &p,segment &p1,segment &p2,int lo,int hi)
{
  p.dsm=p1.sm+p2.sm;if(p.cnt)p.sm=hi-lo+1;else p.sm=p.dsm;
}
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    seg[node].cnt+=vl;
    if(seg[node].cnt)seg[node].sm=hi-lo+1;else seg[node].sm=seg[node].dsm;
    return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,vl);upd(node*2+1,md+1,hi,lt,rt,vl);
  mrge(seg[node],seg[node*2],seg[node*2+1],lo,hi);
}
vector<int>adj[N+2],str[N+2];
int tim,ent[N+2],ext[N+2],mrk[N+2];
void dfs(int node,int par)
{
  ent[node]=++tim;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);
  }
  ext[node]=tim;
}
int ans[N+2],n;
void dfs2(int node,int par)
{
  for(auto x:str[node])
  {
    upd(1,1,n,ent[x],ext[x],1);
    upd(1,1,n,ent[node],ext[node],1);
    //cout<<ent[x]<<" --> "<<ext[x]<<endl;
    //cout<<ent[node]<<" --> "<<ext[node]<<endl;
  }
  ans[node]=seg[1].sm;//cout<<seg[1].sm<<endl;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs2(x,node);
  }
  for(auto x:str[node])
  {
    upd(1,1,n,ent[x],ext[x],-1);
    upd(1,1,n,ent[node],ext[node],-1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int q;cin>>n>>q;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  dfs(1,-1);
  for(int i=1;i<=q;i++)
  {
    int u,v;cin>>u>>v;
    str[u].push_back(v),str[v].push_back(u);
    mrk[u]=1,mrk[v]=1;
  }
  dfs2(1,-1);for(int i=1;i<=n;i++)if(ans[i])ans[i]--;
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}