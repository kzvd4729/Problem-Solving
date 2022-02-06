/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/22/2018 00:30                        
*  solution_verdict: Wrong answer on test 13                 language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 33100 KB                             
*  problem: https://codeforces.com/contest/620/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=4e5;
int tim,st[N+2],ed[N+2],n,m,u,v,cl[N+2],lazy[N*4+2],ty,tmm[N+2];
long seg[N*4+2];
vector<int>adj[N+2];
void dfs_timing(int node,int par)
{
  tim++;
  st[node]=tim;
  tmm[tim]=node;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs_timing(x,node);
  }
  ed[node]=tim;
}
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    seg[node]=(1<<cl[tmm[lo]]);
    return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);
  build(node*2+1,md+1,hi);
  seg[node]=seg[node*2]|seg[node*2+1];
}
void upd(int node,int lo,int hi,int lt,int rt,int cr)
{
  if(lazy[node])
  {
    seg[node]=(1<<lazy[node]);
    if(lo!=hi)
    {
      lazy[node*2]=lazy[node];
      lazy[node*2+1]=lazy[node];
    }
    lazy[node]=0;
  }
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    seg[node]=(1<<cr);
    if(lo!=hi)
    {
      lazy[node*2]=cr;
      lazy[node*2+1]=cr;
    }
    return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,cr);
  upd(node*2+1,md+1,hi,lt,rt,cr);
  seg[node]=seg[node*2]|seg[node*2+1];
}
long query(int node,int lo,int hi,int lt,int rt)
{
  if(lazy[node])
  {
    seg[node]=(1<<lazy[node]);
    if(lo!=hi)
    {
      lazy[node*2]=lazy[node];
      lazy[node*2+1]=lazy[node];
    }
    lazy[node]=0;
  }
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  return query(node*2,lo,md,lt,rt)|query(node*2+1,md+1,hi,lt,rt);
}
int main()
{
  //ofstream cout("out.txt");
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>cl[i];
  for(int i=1;i<n;i++)
  {
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs_timing(1,-1);
  build(1,1,n);
  while(m--)
  {
    cin>>ty;
    if(ty==1)
    {
      cin>>u>>v;
      upd(1,1,n,st[u],ed[u],v);
    }
    else
    {
      cin>>u;
      cout<<__builtin_popcount(query(1,1,n,st[u],ed[u]))<<endl;
    }
  }
  return 0;
}