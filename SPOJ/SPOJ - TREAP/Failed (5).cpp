/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-28 16:54:46                      
*  solution_verdict: Failed                                  language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-TREAP
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=2e9+1;
int nw;
struct treap
{
  int l,r,vl,prio,sz,mn,mx,mng,mxg;
}st[N+2];
void _cal(int node)
{
  if(!node)return ;
  st[node].sz=st[st[node].l].sz+st[st[node].r].sz+1;
  st[node].mn=st[node].mx=st[node].vl;
  st[node].mng=inf;st[node].mxg=-inf;
  if(st[node].l)
  {
    st[node].mn=st[st[node].l].mn;
    st[node].mng=min(st[node].mng,st[st[node].l].mng);
    st[node].mng=min(st[node].mng,st[node].vl-st[st[node].l].mx);
  }
  if(st[node].r)
  {
    st[node].mx=st[st[node].r].mx;
    st[node].mng=min(st[node].mng,st[st[node].r].mng);
    st[node].mng=min(st[node].mng,st[st[node].r].mn-st[node].vl);
  }
  st[node].mxg=st[node].mx-st[node].mn;
}
pair<int,int>split_vl(int node,int vl)
{
  if(!node)return {0,0};
  if(st[node].vl<=vl)
  {
    pair<int,int>p=split_vl(st[node].r,vl);
    st[node].r=p.first;_cal(node);
    return {node,p.second};
  }
  else
  {
    pair<int,int>p=split_vl(st[node].l,vl);
    st[node].l=p.second;_cal(node);
    return {p.first,node};
  }
}
pair<int,int>split_sz(int node,int ss)
{
  if(!node)return {0,0};
  if(st[node].sz<=ss)return {node,0};
  if(!ss)return {0,node};
  if(st[st[node].l].sz>=ss)
  {
    pair<int,int>p=split_sz(st[node].l,ss);
    st[node].l=p.second;_cal(node);
    return {p.first,node};
  }
  else
  {
    pair<int,int>p=split_sz(st[node].r,ss-st[st[node].l].sz-1);
    st[node].r=p.first;_cal(node);
    return {node,p.second};
  }
}
int join(int lt,int rt)
{
  if(!lt)return rt;if(!rt)return lt;
  if(st[lt].prio>=st[rt].prio)
  {
    st[lt].r=join(st[lt].r,rt);_cal(lt);
    return lt;
  }
  else
  {
    st[rt].l=join(lt,st[rt].l);_cal(rt);
    return rt;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,root=0;cin>>n;
  while(n--)
  {
    char ch;cin>>ch;
    if(ch=='I')
    {
      int x;cin>>x;
      pair<int,int>p1=split_vl(root,x);
      pair<int,int>p2=split_vl(p1.first,x-1);
      ++nw;st[nw]={0,0,x,rand(),1,x,x,inf,-inf};
      root=join(p2.first,nw);root=join(root,p1.second);
      //cout<<st[root].mn<<" "<<st[root].mx<<" "<<st[root].mng<<" "<<st[root].mxg<<endl;
    }
    else if(ch=='D')
    {
      int x;cin>>x;
      pair<int,int>p1=split_vl(root,x);
      pair<int,int>p2=split_vl(p1.first,x-1);
      root=join(p2.first,p1.second);
    }
    else if(ch=='N')
    {
      int x,y;cin>>x>>y;x++,y++;
      pair<int,int>p1=split_sz(root,y);
      pair<int,int>p2=split_sz(p1.first,x-1);
      if(st[p2.second].sz<=1)cout<<-1<<endl;
      else cout<<st[p2.second].mng<<endl;
      root=join(p2.first,p2.second);root=join(root,p1.second);
    }
    else
    {
      int x,y;cin>>x>>y;x++,y++;
      pair<int,int>p1=split_sz(root,y);
      pair<int,int>p2=split_sz(p1.first,x-1);
      if(st[p2.second].sz<=1)cout<<-1<<endl;
      else cout<<st[p2.second].mxg<<endl;
      root=join(p2.first,p2.second);root=join(root,p1.second);
    }
  }
  return 0;
}