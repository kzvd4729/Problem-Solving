/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/28/2018 22:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 686 ms                                          memory_used: 4700 KB                              
*  problem: https://codeforces.com/contest/863/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int nw;
struct treap
{
  int lt,rt,dt,pri,sz,lz;
}bst[N+2];
void _cal(int node)
{
  bst[node].sz=bst[bst[node].lt].sz+bst[bst[node].rt].sz+1;
}
void too_lazy(int node)
{
  if(bst[node].lz)
  {
    swap(bst[node].lt,bst[node].rt);
    if(bst[node].lt)bst[bst[node].lt].lz^=1;
    if(bst[node].rt)bst[bst[node].rt].lz^=1;
    bst[node].lz=0;
  }
}
pair<int,int>split_sz(int node,int ss)
{
  too_lazy(node);
  if(!node)return {0,0};pair<int,int>p;
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
int join(int lt,int rt)
{
  too_lazy(lt);too_lazy(rt);
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
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q,m,root=0;cin>>n>>q>>m;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;++nw;
    bst[nw]={0,0,x,rand(),1,0};
    root=join(root,nw);
  }
  while(q--)
  {
    int ty,lt,rt;cin>>ty>>lt>>rt;
    if(ty==1)
    {
      pair<int,int>p1=split_sz(root,rt);
      pair<int,int>p2=split_sz(p1.first,lt-1);
      pair<int,int>p3=split_sz(p2.second,bst[p2.second].sz-1);
      root=join(p3.second,p3.first);
      root=join(p2.first,root);root=join(root,p1.second);
    }
    else
    {
      pair<int,int>p1=split_sz(root,rt);
      pair<int,int>p2=split_sz(p1.first,lt-1);
      bst[p2.second].lz=1;
      root=join(p2.first,p2.second);
      root=join(root,p1.second);
    }
  }
  while(m--)
  {
    int x;cin>>x;
    pair<int,int>p1=split_sz(root,x);
    pair<int,int>p2=split_sz(p1.first,x-1);
    cout<<bst[p2.second].dt<<" ";
    root=join(p2.first,p2.second);root=join(root,p1.second);
  }
  cout<<endl;
  return 0;
}