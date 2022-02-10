/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-24 18:26:21                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1060                                       memory_used (MB): 20.5                            
*  problem: https://vjudge.net/problem/SPOJ-ORDERSET
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;

/*********************** Treap **********************/
int Tr;
struct Treap
{
  int lt,rt,dt,pri,sz;
}Bst[N+2];
void _Cal(int node)
{
  Bst[node].sz=Bst[Bst[node].lt].sz+Bst[Bst[node].rt].sz+1;
}
pair<int,int>Split_vl(int node,int vl)
{
  if(!node)return {0,0};pair<int,int>p;
  if(Bst[node].dt<=vl)
  {
    p=Split_vl(Bst[node].rt,vl);
    Bst[node].rt=p.first;_Cal(node);
    return {node,p.second};
  }
  else
  {
    p=Split_vl(Bst[node].lt,vl);
    Bst[node].lt=p.second;_Cal(node);
    return {p.first,node};
  }
}
pair<int,int>Split_sz(int node,int ss)
{
  if(!node)return {0,0};pair<int,int>p;
  if(Bst[Bst[node].lt].sz>=ss)
  {
    p=Split_sz(Bst[node].lt,ss);
    Bst[node].lt=p.second;_Cal(node);
    return {p.first,node};
  }
  else
  {
    p=Split_sz(Bst[node].rt,ss-Bst[Bst[node].lt].sz-1);
    Bst[node].rt=p.first;_Cal(node);
    return {node,p.second};
  }
}
int Join(int lt,int rt)
{
  if(!lt)return rt;if(!rt)return lt;
  if(Bst[lt].pri>=Bst[rt].pri)
  {
    Bst[lt].rt=Join(Bst[lt].rt,rt);
    _Cal(lt);return lt;
  }
  else
  {
    Bst[rt].lt=Join(lt,Bst[rt].lt);
    _Cal(rt);return rt;
  }
}
////////////////////////////////////////////////////////
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
      pair<int,int>p1=Split_vl(root,x);
      pair<int,int>p2=Split_vl(p1.first,x-1);
      ++Tr;Bst[Tr]={0,0,x,rand(),1};
      root=Join(Join(p2.first,Tr),p1.second);
    }
    else if(ch=='D')
    {
      int x;cin>>x;
      pair<int,int>p1=Split_vl(root,x);
      pair<int,int>p2=Split_vl(p1.first,x-1);
      root=Join(p2.first,p1.second);
    }
    else if(ch=='K')
    {
      int x;cin>>x;
      if(Bst[root].sz<x)
      {
        cout<<"invalid"<<endl;continue;
      }
      pair<int,int>p1=Split_sz(root,x-1);
      pair<int,int>p2=Split_sz(p1.second,1);
      cout<<Bst[p2.first].dt<<endl;
      root=Join(p1.first,Join(p2.first,p2.second));
    }
    else
    {
      int x;cin>>x;
      pair<int,int>p1=Split_vl(root,x-1);
      cout<<Bst[p1.first].sz<<endl;
      root=Join(p1.first,p1.second);
    }
  }
  return 0;
}