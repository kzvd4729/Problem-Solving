/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/03/2020 22:45                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 35200 KB                             
*  problem: https://codeforces.com/gym/102787/problem/D
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=5e5;
const long inf=1e18+1;
int tr;
struct treap
{
  int lt,rt;long dt;int pri,sz;
  long ad,mx,sm,firstMx,secondMx,fr;
}bst[N+2];
void merge(treap &a,treap b)
{
  a.sm+=b.sm;a.sz+=b.sz;
  if(a.firstMx==b.firstMx)
  {
    a.secondMx=max(a.secondMx,b.secondMx);
    a.fr+=b.fr;
  }
  else if(a.firstMx>b.firstMx)
  {
    a.secondMx=max(a.secondMx,b.firstMx);
  }
  else
  {
    a.secondMx=max(a.firstMx,b.secondMx);
    a.firstMx=b.firstMx;
    a.fr=b.fr;
  }
}
void pushDown(int nd)
{
  if(nd==0)return ;
  int l=bst[nd].lt,r=bst[nd].rt;
   bst[nd].dt+=bst[nd].ad;/////
  bst[nd].dt=min(bst[nd].dt,bst[nd].mx);/////
   bst[nd].sm+=bst[nd].sz*bst[nd].ad;
  bst[nd].firstMx+=bst[nd].ad,bst[nd].secondMx+=bst[nd].ad;
   if(l)bst[l].ad+=bst[nd].ad,bst[l].mx+=bst[nd].ad;
  if(r)bst[r].ad+=bst[nd].ad,bst[r].mx+=bst[nd].ad;
   if(bst[nd].mx<bst[nd].firstMx)
  {
    bst[nd].sm-=(bst[nd].firstMx-bst[nd].mx)*bst[nd].fr;
    bst[nd].firstMx=bst[nd].mx;
  }
  if(l)bst[l].mx=min(bst[l].mx,bst[nd].mx);
  if(r)bst[r].mx=min(bst[r].mx,bst[nd].mx);
   bst[nd].ad=0,bst[nd].mx=inf;
}
void cal(int nd)
{
  int l=bst[nd].lt,r=bst[nd].rt;
  pushDown(nd);pushDown(l);pushDown(r);
   bst[nd].sz=1;bst[nd].sm=bst[nd].dt;
  bst[nd].firstMx=bst[nd].dt,bst[nd].secondMx=-inf;
  bst[nd].fr=1;
   if(l)merge(bst[nd],bst[l]);
  if(r)merge(bst[nd],bst[r]);
 }
pair<int,int>splitbySize(int node,int ss)
{
  pushDown(node);pushDown(bst[node].lt);
  pushDown(bst[node].rt);
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
  pushDown(lt);pushDown(bst[lt].lt);pushDown(bst[lt].rt);
  pushDown(rt);pushDown(bst[rt].lt);pushDown(bst[rt].rt);
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
void trim(int nd,long x)
{
  if(nd==0)return ;
  pushDown(nd);pushDown(bst[nd].lt);pushDown(bst[nd].rt);
  if(bst[nd].firstMx<=x)return;
   if(bst[nd].secondMx<=x)
  {
    bst[nd].mx=x;pushDown(nd);
    return ;
  }
  trim(bst[nd].lt,x);trim(bst[nd].rt,x);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,q;cin>>n>>q;int root=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    bst[i]={0,0,x,rand(),1,0,inf,x,x,-inf,1};
    root=join(root,i);
  }
  while(q--)
  {
    int ty,l,r;cin>>ty>>l>>r;
    pair<int,int>p1=splitbySize(root,l-1);
    pair<int,int>p2=splitbySize(p1.second,r-l+1);
    if(ty==1)
    {
      int h;cin>>h;trim(p2.first,h);
      root=join(p1.first,join(p2.first,p2.second));
    }
    else if(ty==2)
    {
      root=join(p1.first,p2.second);
      root=join(root,p2.first);
    }
    else
    {
      int x;cin>>x;
      bst[p2.first].ad+=x;bst[p2.first].mx+=x;
      if(bst[p2.first].mx>inf)bst[p2.first].mx=inf;
      pushDown(p2.first);
      root=join(p1.first,join(p2.first,p2.second));
    }
    pushDown(root);
    cout<<bst[root].sm<<'\n';
  }
  return 0;
}