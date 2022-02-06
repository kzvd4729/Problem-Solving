/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/14/2018 14:21                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/226/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,rt,sz[N+2],level[N+2];
int anc[N+2],st[N+2],tim,nw=1;
struct segment
{
  int l,r,sum;
}seg[65*N+2];
vector<int>adj[N+2];
void upd(int node,int lo,int hi,int pnode,int id)
{
  if(lo==hi)
  {
    seg[node].sum=seg[pnode].sum+1;
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)
  {
    if(!seg[node].l)seg[node].l=++nw;
    upd(seg[node].l,lo,md,seg[pnode].l,id);
    seg[node].r=seg[pnode].r;
  }
  else
  {
    if(!seg[node].r)seg[node].r=++nw;
    upd(seg[node].r,md+1,hi,seg[pnode].r,id);
    seg[node].l=seg[pnode].l;
  }
  seg[node].sum=seg[seg[node].l].sum+seg[seg[node].r].sum;
}
int query(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node].sum;
  int md=(lo+hi)/2;
  int p1=query(seg[node].l,lo,md,lt,rt);
  int p2=query(seg[node].r,md+1,hi,lt,rt);
  return p1+p2;
}
void dfs(int node,int par,int h)
{
  sz[node]=1;level[node]=h+1;parent[node]=par;
  for(auto &xx:adj[node])
  {
    dfs(xx,node,h+1);sz[node]+=sz[xx];
    if(sz[xx]>sz[adj[node][0]])
      swap(xx,adj[node][0]);
  }
}
void hld(int node,int par)
{
  st[node]=++tim;
  for(auto xx:adj[node])
  {
    anc[xx]=(xx==adj[node][0]?anc[node]:xx);
    hld(xx,node);
  }
}
void sparse(void)
{
  for(int i=1;i<=n;i++)sp[i][0]=parent[i];
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    if(x==0)rt=i;
    else adj[i].push_back(x);
  }
  dfs(rt,-1,1);hld(rt,-1);
  int q;cin>>q;
   return 0;
}