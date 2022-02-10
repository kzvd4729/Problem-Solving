/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-28 20:02:21                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1120                                       memory_used (MB): 20.5                            
*  problem: https://vjudge.net/problem/SPOJ-ORDERSET
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int nw;
struct treap
{
  int lt,rt,dt,pri,sz;
}bst[N+2];
void _cal(int node)
{
  bst[node].sz=bst[bst[node].lt].sz+bst[bst[node].rt].sz+1;
}
pair<int,int>split_vl(int node,int vl)
{
  if(!node)return {0,0};pair<int,int>p;
  if(bst[node].dt<=vl)
  {
    p=split_vl(bst[node].rt,vl);
    bst[node].rt=p.first;_cal(node);
    return {node,p.second};
  }
  else
  {
    p=split_vl(bst[node].lt,vl);
    bst[node].lt=p.second;_cal(node);
    return {p.first,node};
  }
}
pair<int,int>split_sz(int node,int ss)
{
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
  int n,root=0;cin>>n;
  while(n--)
  {
    char ch;cin>>ch;
    if(ch=='I')
    {
      int x;cin>>x;
      pair<int,int>p1=split_vl(root,x);
      pair<int,int>p2=split_vl(p1.first,x-1);
      ++nw;bst[nw]={0,0,x,rand(),1};
      root=join(join(p2.first,nw),p1.second);
    }
    else if(ch=='D')
    {
      int x;cin>>x;
      pair<int,int>p1=split_vl(root,x);
      pair<int,int>p2=split_vl(p1.first,x-1);
      root=join(p2.first,p1.second);
    }
    else if(ch=='K')
    {
      int x;cin>>x;
      if(bst[root].sz<x)
      {
        cout<<"invalid"<<endl;continue;
      }
      pair<int,int>p1=split_sz(root,x-1);
      pair<int,int>p2=split_sz(p1.second,1);
      cout<<bst[p2.first].dt<<endl;
      root=join(p1.first,join(p2.first,p2.second));
    }
    else
    {
      int x;cin>>x;
      pair<int,int>p1=split_vl(root,x-1);
      cout<<bst[p1.first].sz<<endl;
      root=join(p1.first,p1.second);
    }
  }
  return 0;
}