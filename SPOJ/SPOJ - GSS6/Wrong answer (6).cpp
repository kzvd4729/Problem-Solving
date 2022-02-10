/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-10-01 01:15:18                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-GSS6
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5,inf=1e14;
long nw,f;
struct treap
{
  long lt,rt,sz,pri,dt,mxs,tsm,lsm,rsm;
}bst[N+N+N+2];
void _cal(long node)
{
  if(!node)return ;
  long lc=bst[node].lt,rc=bst[node].rt;

  bst[node].sz=bst[lc].sz+bst[rc].sz+1;
  bst[node].mxs=bst[node].dt;
  bst[node].lsm=-inf;bst[node].rsm=-inf;

  bst[node].tsm=bst[lc].tsm+bst[rc].tsm+bst[node].dt;

  if(lc)bst[node].lsm=max(bst[node].lsm,bst[lc].lsm);
  bst[node].lsm=max(bst[node].lsm,bst[lc].tsm+bst[node].dt);
  bst[node].lsm=max(bst[node].lsm,bst[lc].tsm+bst[node].dt+bst[rc].lsm);
  bst[node].lsm=max(bst[node].lsm,bst[node].tsm);

  if(rc)bst[node].rsm=max(bst[node].rsm,bst[rc].rsm);
  bst[node].rsm=max(bst[node].rsm,bst[rc].tsm+bst[node].dt);
  bst[node].rsm=max(bst[node].rsm,bst[rc].tsm+bst[node].dt+bst[lc].rsm);
  bst[node].rsm=max(bst[node].rsm,bst[node].tsm);

  if(lc)bst[node].mxs=max(bst[node].mxs,bst[lc].mxs);
  if(rc)bst[node].mxs=max(bst[node].mxs,bst[rc].mxs);

  bst[node].mxs=max(bst[node].mxs,max(bst[node].lsm,bst[node].rsm));
  bst[node].mxs=max(bst[node].mxs,bst[lc].rsm+bst[node].dt+bst[rc].lsm);
  bst[node].mxs=max(bst[node].mxs,bst[lc].rsm+bst[node].dt);
  bst[node].mxs=max(bst[node].mxs,bst[rc].lsm+bst[node].dt);
}
pair<long,long>split_sz(long node,long ss)
{
  if(!node)return {0,0};pair<long,long>p;
  if(bst[bst[node].lt].sz>=ss)
  {
    p=split_sz(bst[node].lt,ss);
    bst[node].lt=p.second;_cal(node);
    return {p.first,node};
  }
  else
  {
    p=split_sz(bst[node].rt,ss-bst[bst[node].lt].sz-1);
    bst[node].rt=p.first;_cal(node);
    return {node,p.second};
  }
}
long join(long lt,long rt)
{
  if(!lt)return rt;if(!rt)return lt;
  if(bst[lt].pri>=bst[rt].pri)
  {
    bst[lt].rt=join(bst[lt].rt,rt);
    _cal(lt);return lt;
  }
  else
  {
    bst[rt].lt=join(lt,bst[rt].lt);
    _cal(rt);return rt;
  }
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  long n,root=0;cin>>n;
  for(long i=1;i<=n;i++)
  {
    long x;cin>>x;
    ++nw;bst[nw]={0,0,1,rand(),x,x,x,x,x};
    root=join(root,nw);
  }
  long q;cin>>q;pair<long,long>p1,p2;
  while(q--)
  {
    char ch;cin>>ch;
    if(ch=='I')
    {
      long x,y;cin>>x>>y;
      p1=split_sz(root,x-1);
      ++nw;bst[nw]={0,0,1,rand(),y,y,y,y,y};
      root=join(p1.first,nw);root=join(root,p1.second);
    }
    else if(ch=='D')
    {
      long x;cin>>x;
      p1=split_sz(root,x);p2=split_sz(p1.first,x-1);
      root=join(p2.first,p1.second);
    }
    else if(ch=='R')
    {
      long x,y;cin>>x>>y;
      p1=split_sz(root,x);p2=split_sz(p1.first,x-1);
      ++nw;bst[nw]={0,0,1,rand(),y,y,y,y,y};
      root=join(join(p2.first,nw),p1.second);
    }
    else
    {
      long lt,rt;cin>>lt>>rt;
      p1=split_sz(root,rt);p2=split_sz(p1.first,lt-1);
      if(bst[p2.second].mxs<0)cout<<0<<endl;
      else cout<<bst[p2.second].mxs<<endl;
      root=join(join(p2.first,p2.second),p1.second);
    }
  }
  return 0;
}