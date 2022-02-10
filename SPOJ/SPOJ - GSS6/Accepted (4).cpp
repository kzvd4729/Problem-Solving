/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-12-15 20:01:43                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1840                                       memory_used (MB): 10.2                            
*  problem: https://vjudge.net/problem/SPOJ-GSS6
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5,inf=2e9;
int tr;
struct treap
{
  int lt,rt,sz,pri,dt,mx,sm,ls,rs;
}bst[N+N+2];
void cal(int node)
{
  if(!node)return ;
  int lc=bst[node].lt,rc=bst[node].rt;

  bst[node].sz=bst[lc].sz+bst[rc].sz+1;
  bst[node].mx=bst[node].dt;
  bst[node].ls=-inf;bst[node].rs=-inf;

  bst[node].sm=bst[lc].sm+bst[rc].sm+bst[node].dt;

  if(lc)bst[node].ls=max(bst[node].ls,bst[lc].ls);
  bst[node].ls=max(bst[node].ls,bst[lc].sm+bst[node].dt);
  bst[node].ls=max(bst[node].ls,bst[lc].sm+bst[node].dt+bst[rc].ls);
  bst[node].ls=max(bst[node].ls,bst[node].sm);

  if(rc)bst[node].rs=max(bst[node].rs,bst[rc].rs);
  bst[node].rs=max(bst[node].rs,bst[rc].sm+bst[node].dt);
  bst[node].rs=max(bst[node].rs,bst[rc].sm+bst[node].dt+bst[lc].rs);
  bst[node].rs=max(bst[node].rs,bst[node].sm);

  if(lc)bst[node].mx=max(bst[node].mx,bst[lc].mx);
  if(rc)bst[node].mx=max(bst[node].mx,bst[rc].mx);

  bst[node].mx=max(bst[node].mx,max(bst[node].ls,bst[node].rs));
  bst[node].mx=max(bst[node].mx,bst[lc].rs+bst[node].dt+bst[rc].ls);
  bst[node].mx=max(bst[node].mx,bst[lc].rs+bst[node].dt);
  bst[node].mx=max(bst[node].mx,bst[rc].ls+bst[node].dt);
}
pair<int,int>split_sz(int node,int ss)
{
  if(!node)return {0,0};pair<int,int>p;
  if(bst[bst[node].lt].sz>=ss)
  {
    p=split_sz(bst[node].lt,ss);
    bst[node].lt=p.second;cal(node);
    return {p.first,node};
  }
  else
  {
    p=split_sz(bst[node].rt,ss-bst[bst[node].lt].sz-1);
    bst[node].rt=p.first;cal(node);
    return {node,p.second};
  }
}
int join(int lt,int rt)
{
  if(!lt)return rt;if(!rt)return lt;
  if(bst[lt].pri>=bst[rt].pri)
  {
    bst[lt].rt=join(bst[lt].rt,rt);
    cal(lt);return lt;
  }
  else
  {
    bst[rt].lt=join(lt,bst[rt].lt);
    cal(rt);return rt;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,root=0;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    ++tr;bst[tr]={0,0,1,rand(),x,x,x,x,x};
    root=join(root,tr);
  }
  int q;cin>>q;pair<int,int>p1,p2;
  while(q--)
  {
    char ch;cin>>ch;
    if(ch=='I')
    {
      int x,y;cin>>x>>y;
      p1=split_sz(root,x-1);
      ++tr;bst[tr]={0,0,1,rand(),y,y,y,y,y};
      root=join(p1.first,tr);root=join(root,p1.second);
    }
    else if(ch=='D')
    {
      int x;cin>>x;
      p1=split_sz(root,x);p2=split_sz(p1.first,x-1);
      root=join(p2.first,p1.second);
    }
    else if(ch=='R')
    {
      int x,y;cin>>x>>y;
      p1=split_sz(root,x);p2=split_sz(p1.first,x-1);
      ++tr;bst[tr]={0,0,1,rand(),y,y,y,y,y};
      root=join(join(p2.first,tr),p1.second);
    }
    else
    {
      int lt,rt;cin>>lt>>rt;
      p1=split_sz(root,rt);p2=split_sz(p1.first,lt-1);
      //if(bst[p2.second].mx<0)cout<<0<<endl;
      cout<<bst[p2.second].mx<<"\n";
      root=join(join(p2.first,p2.second),p1.second);
    }
  }
  return 0;
}