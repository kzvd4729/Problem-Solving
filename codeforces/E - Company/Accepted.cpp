/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/15/2018 20:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 561 ms                                          memory_used: 25200 KB                             
*  problem: https://codeforces.com/contest/1062/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,sp[N+2][22],parent[N+2],level[N+2];
int ent[N+2],tim;
vector<int>adj[N+2];
struct segment
{
  int vl,id;
}seg_mn[5*N+2],seg_mx[5*N+2];
void build_mn(int node,int lo,int hi)
{
  if(lo==hi)
  {
    seg_mn[node]={ent[lo],lo};
    return ;
  }
  int md=(lo+hi)/2;
  build_mn(node*2,lo,md);
  build_mn(node*2+1,md+1,hi);
  if(seg_mn[node*2].vl<seg_mn[node*2+1].vl)
    seg_mn[node]=seg_mn[node*2];
  else seg_mn[node]=seg_mn[node*2+1];
}
segment qry_mn(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return {N+2,0};
  if(lo>=lt&&hi<=rt)return seg_mn[node];
  int md=(lo+hi)/2;
  segment p1=qry_mn(node*2,lo,md,lt,rt);
  segment p2=qry_mn(node*2+1,md+1,hi,lt,rt);
  if(p1.vl<p2.vl)return p1;
  else return p2;
}
void build_mx(int node,int lo,int hi)
{
  if(lo==hi)
  {
    seg_mx[node]={ent[lo],lo};
    return ;
  }
  int md=(lo+hi)/2;
  build_mx(node*2,lo,md);
  build_mx(node*2+1,md+1,hi);
  if(seg_mx[node*2].vl>seg_mx[node*2+1].vl)
    seg_mx[node]=seg_mx[node*2];
  else seg_mx[node]=seg_mx[node*2+1];
}
segment qry_mx(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return {0,0};
  if(lo>=lt&&hi<=rt)return seg_mx[node];
  int md=(lo+hi)/2;
  segment p1=qry_mx(node*2,lo,md,lt,rt);
  segment p2=qry_mx(node*2+1,md+1,hi,lt,rt);
  if(p1.vl>p2.vl)return p1;
  else return p2;
}
void dfs(int node,int par,int lv)
{
  parent[node]=par;level[node]=lv;
  ent[node]=++tim;
  for(auto x:adj[node])
    dfs(x,node,lv+1);
}
void build_sparse(void)
{
  memset(sp,-1,sizeof(sp));
  for(int i=1;i<=n;i++)
    sp[i][0]=parent[i];
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if(sp[i][j-1]!=-1)
        sp[i][j]=sp[sp[i][j-1]][j-1];
    }
  }
}
int lca(int u,int v)
{
  if(level[u]<level[v])swap(u,v);
  for(int i=20;i>=0;i--)
  {
    if(sp[u][i]==-1)continue;
    if(level[sp[u][i]]>=level[v])
      u=sp[u][i];
  }
  if(u==v)return u;
  for(int i=20;i>=0;i--)
  {
    if(sp[u][i]==-1||sp[v][i]==-1)continue;
    if(sp[u][i]==sp[v][i])continue;
    u=sp[u][i];v=sp[v][i];
  }
  return parent[u];
}
segment do_min(int lt,int rt)
{
  segment p1,p2,p3,p4,p5;
  p1=qry_mn(1,1,n,lt,rt);p2=qry_mx(1,1,n,lt,rt);
  if(p1.id+1<=rt)
    p3=qry_mn(1,1,n,p1.id+1,rt);
  else p3={N+2,0};
   if(p1.id-1>=lt)
    p4=qry_mn(1,1,n,lt,p1.id-1);
  else p4={N+2,0};
  if(p3.vl<p4.vl)p5=p3;
  else p5=p4;
  return {lca(p5.id,p2.id),p1.id};
}
segment do_max(int lt,int rt)
{
  segment p1,p2,p3,p4,p5;
  p1=qry_mn(1,1,n,lt,rt);p2=qry_mx(1,1,n,lt,rt);
  if(p2.id+1<=rt)
    p3=qry_mx(1,1,n,p2.id+1,rt);
  else p3={0,0};
   if(p2.id-1>=lt)
    p4=qry_mx(1,1,n,lt,p2.id-1);
  else p4={0,0};
  if(p3.vl>p4.vl)p5=p3;
  else p5=p4;
  return {lca(p5.id,p1.id),p2.id};
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int q;cin>>n>>q;
  for(int i=2;i<=n;i++)
  {
    int p;cin>>p;
    adj[p].push_back(i);
  }
  dfs(1,-1,0);build_sparse();
  build_mn(1,1,n);build_mx(1,1,n);
  while(q--)
  {
    int lt,rt;cin>>lt>>rt;
    segment p1=do_min(lt,rt);
    segment p2=do_max(lt,rt);
    if(level[p1.vl]>level[p2.vl])
      cout<<p1.id<<" "<<level[p1.vl]<<"\n";
    else cout<<p2.id<<" "<<level[p2.vl]<<"\n";
  }
  return 0;
}