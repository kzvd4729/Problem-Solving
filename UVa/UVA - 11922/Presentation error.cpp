/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-18 14:55:36                      
*  solution_verdict: Presentation error                      language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11922
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int tr;
struct treap
{
  int lt,rt,dt,pri,sz,lz;
}bst[N+2];
void cal(int node)
{
  bst[node].sz=bst[bst[node].lt].sz+bst[bst[node].rt].sz+1;
}
void tooLazy(int node)
{
  if(!bst[node].lz)return ;
  swap(bst[node].lt,bst[node].rt);

  if(bst[node].lt)bst[bst[node].lt].lz^=1;
  if(bst[node].rt)bst[bst[node].rt].lz^=1;

  bst[node].lz=0;
}
pair<int,int>splitbySize(int node,int ss)
{
  tooLazy(node);
  if(!node)return {0,0};pair<int,int>p;
  if(bst[bst[node].lt].sz>=ss)
  {
    p=splitbySize(bst[node].lt,ss);
    bst[node].lt=p.second;cal(node);
    return {p.first,node};
  }
  else
  {
    p=splitbySize(bst[node].rt,ss-bst[bst[node].lt].sz-1);
    bst[node].rt=p.first;cal(node);
    return {node,p.second};
  }
}
int join(int lt,int rt)
{
  tooLazy(lt);tooLazy(rt);
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
void print(int root,int n)
{
  for(int i=1;i<=n;i++)
  {
    pair<int,int>p=splitbySize(root,1);
    cout<<bst[p.first].dt<<"\n";
    root=p.second;
  }
  cout<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  int root=0;
  for(int i=1;i<=n;i++)
  {
    bst[++tr]={0,0,i,rand(),1,0};
    root=join(root,tr);
  }
  //print(root,n);
  while(m--)
  {
    int u,v;cin>>u>>v;
    pair<int,int>p1=splitbySize(root,u-1);
    pair<int,int>p2=splitbySize(p1.second,v-u+1);
    root=join(p1.first,p2.second);

    bst[p2.first].lz^=1;

    root=join(root,p2.first);
  }
  print(root,n);
  return 0;
}