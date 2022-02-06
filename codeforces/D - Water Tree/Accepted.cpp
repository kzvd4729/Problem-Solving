/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/15/2018 16:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1482 ms                                         memory_used: 72500 KB                             
*  problem: https://codeforces.com/contest/343/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
int n,sz[N+2],in[N+2],out[N+2],tim,num[N+2];
int anc[N+2],seg[4*N+2],lazy[4*N+2],parent[N+2];
vector<int>adj[N+2];
void too_lazy(int node,int lo,int hi)
{
  if(lazy[node]==-1)return ;
  seg[node]=lazy[node];
  if(lo!=hi)
  {
    lazy[node*2]=lazy[node];
    lazy[node*2+1]=lazy[node];
  }
  lazy[node]=-1;
}
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  too_lazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lazy[node]=vl;too_lazy(node,lo,hi);
    return;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,vl);
  upd(node*2+1,md+1,hi,lt,rt,vl);
  seg[node]=seg[node*2]|seg[node*2+1];
}
int qry(int node,int lo,int hi,int id)
{
  too_lazy(node,lo,hi);
  if(lo>id||hi<id)return 0;
  if(lo==hi)return seg[node];
  int md=(lo+hi)/2;
  int p1=qry(node*2,lo,md,id);
  int p2=qry(node*2+1,md+1,hi,id);
  return p1|p2;
}
void reckon(int node,int par)
{
  sz[node]=1;parent[node]=par;
  for(auto &x:adj[node])
  {
    if(x==par)continue;
    reckon(x,node);sz[node]+=sz[x];
    if(sz[x]>=sz[adj[node][0]])swap(x,adj[node][0]);
  }
}
void hld(int node,int par)
{
  in[node]=++tim;num[node]=tim;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(x==adj[node][0])anc[x]=anc[node];
    else anc[x]=x;hld(x,node);
  }
  out[node]=tim;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  anc[1]=1;reckon(1,-1);hld(1,-1);
  memset(lazy,-1,sizeof(lazy));
  int q;cin>>q;
  while(q--)
  {
    int ty,x;cin>>ty>>x;
    if(ty==1)upd(1,1,n,in[x],out[x],1);
    else if(ty==2)
    {
      while(x!=-1)
      {
        upd(1,1,n,in[anc[x]],in[x],0);
        x=parent[anc[x]];
      }
    }
    else cout<<qry(1,1,n,num[x])<<"\n";
  }
  return 0;
}