/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-12-15 19:53:32                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-GSS6
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=1e9+1;

int tr;
struct treap
{
  int lt,rt,sz,pri,dt,ls,rs,sm,mx;
}bst[N+2];
void mrge(treap &p,treap p1,treap p2)
{
  p.sm=p1.sm+p2.sm;
  p.ls=max(p1.ls,p1.sm+p2.ls);
  p.rs=max(p2.rs,p1.rs+p2.sm);
  p.mx=max(max(p1.mx,p2.mx),p1.rs+p2.ls);
}
void cal(int node)
{
  if(node==0)assert(0);
  bst[node].sz=bst[bst[node].lt].sz+bst[bst[node].rt].sz+1;

  treap tmp=bst[node];
  tmp.ls=tmp.dt,tmp.rs=tmp.dt,tmp.sm=tmp.dt,tmp.mx=tmp.dt;
  mrge(bst[node],bst[bst[node].lt],tmp);

  tmp=bst[node];
  mrge(bst[node],tmp,bst[bst[node].rt]);

  treap p=bst[node],p1=bst[bst[node].lt],p2=bst[bst[node].rt];
  //cout<<p.dt<<" | "<<p1.ls<<" "<<p1.rs<<" "<<p1.mx<<" "<<p1.sm<<" | "<<p2.ls<<" "<<p2.rs<<" "<<p2.mx<<" "<<p2.sm<<" == "<<p.ls<<" "<<p.rs<<" "<<p.mx<<" "<<p.sm<<endl;
}
pair<int,int>splitbySize(int node,int ss)
{
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
  if(!lt)return rt;if(!rt)return lt;
  if(bst[lt].pri>=bst[rt].pri)
  {
    bst[lt].rt=join(bst[lt].rt,rt);cal(lt);return lt;
  }
  else
  {
    bst[rt].lt=join(lt,bst[rt].lt);cal(rt);return rt;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,root=0;cin>>n;
  bst[0]={0,0,0,0,-inf,0,-0,0,-inf};
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
      p1=splitbySize(root,x-1);
      ++tr;bst[tr]={0,0,1,rand(),y,y,y,y,y};
      root=join(p1.first,tr);root=join(root,p1.second);

      //cout<<bst[root].mx<<endl;
    }
    else if(ch=='D')
    {
      int x;cin>>x;
      p1=splitbySize(root,x);p2=splitbySize(p1.first,x-1);
      root=join(p2.first,p1.second);
    }
    else if(ch=='R')
    {
      int x,y;cin>>x>>y;
      p1=splitbySize(root,x);p2=splitbySize(p1.first,x-1);
      ++tr;bst[tr]={0,0,1,rand(),y,y,y,y,y};
      root=join(join(p2.first,tr),p1.second);
    }
    else
    {
      int lt,rt;cin>>lt>>rt;
      p1=splitbySize(root,rt);p2=splitbySize(p1.first,lt-1);
      //cout<<bst[bst[p2.second].rt].dt<<endl;
      cout<<bst[p2.second].mx<<"\n";
      root=join(join(p2.first,p2.second),p1.second);
    }
    //cout<<"ok"<<endl;
  }
  return 0;
}