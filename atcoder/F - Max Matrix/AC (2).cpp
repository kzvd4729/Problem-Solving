/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-03 22:46:56                      
*  solution_verdict: AC                                      language: C++ (GCC 9.2.1)                         
*  run_time: 462 ms                                          memory_used: 24416 KB                             
*  problem: https://atcoder.jp/contests/jsc2021/tasks/jsc2021_f
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
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 struct abcd
{
  int tr;
  struct treap
  {
    int lt,rt,dt,pri,sz;
    long sm;
  }bst[N+2];
  void cal(int nd)
  {
    int l=bst[nd].lt,r=bst[nd].rt;
    bst[nd].sz=bst[l].sz+bst[r].sz+1;
     bst[nd].sm=bst[l].sm+bst[r].sm+bst[nd].dt;
  }
  //left tree will contain value <= vl.
  pair<int,int>splitbyValue(int nd,int vl)
  {
    if(!nd)return {0,0};pair<int,int>p;
    if(bst[nd].dt<=vl)
    {
      p=splitbyValue(bst[nd].rt,vl);
      bst[nd].rt=p.first;cal(nd);
      return {nd,p.second};
    }
    else
    {
      p=splitbyValue(bst[nd].lt,vl);
      bst[nd].lt=p.second;cal(nd);
      return {p.first,nd};
    }
  }
  pair<int,int>splitbySize(int nd,int ss)
  {
    if(!nd)return {0,0};pair<int,int>p;
    if(bst[bst[nd].lt].sz>=ss)
    {
      p=splitbySize(bst[nd].lt,ss);
      bst[nd].lt=p.second;cal(nd);
      return {p.first,nd};
    }
    else
    {
      p=splitbySize(bst[nd].rt,ss-bst[bst[nd].lt].sz-1);
      bst[nd].rt=p.first;cal(nd);
      return {nd,p.second};
    }
  }
  //lt and rt are bst and max element of lt <= minimum of rt
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
  int add(int rt,int vl)
  {
    pair<int,int>p=splitbyValue(rt,vl);
     bst[++tr]={0,0,vl,rand(),1,vl};
    rt=join(p.first,tr);
    rt=join(rt,p.second);
     return rt;
  }
  int erase(int rt,int vl)
  {
    pair<int,int>p=splitbyValue(rt,vl-1);
    pair<int,int>p2=splitbySize(p.second,1);
     return join(p.first,p2.second);
  }
}lft,rgt;
 int a[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m,q;cin>>n>>m>>q;
   long ans=0;int rt1=0,rt2=0;
   for(int i=1;i<=n;i++)rt1=lft.add(rt1,0);
  for(int i=1;i<=m;i++)rt2=rgt.add(rt2,0);
   while(q--)
  {
    int ty;cin>>ty;
     if(ty==1)
    {
      int x,y;cin>>x>>y;
       pair<int,int>p=rgt.splitbyValue(rt2,a[x]);
      ans-=(1LL*rgt.bst[p.first].sz*a[x]+rgt.bst[p.second].sm);
      rt2=rgt.join(p.first,p.second);
       rt1=lft.erase(rt1,a[x]);
       a[x]=y;
      p=rgt.splitbyValue(rt2,a[x]);
      ans+=(1LL*rgt.bst[p.first].sz*a[x]+rgt.bst[p.second].sm);
      rt2=rgt.join(p.first,p.second);
       rt1=lft.add(rt1,a[x]);
     }
    else
    {
      int x,y;cin>>x>>y;
       pair<int,int>p=lft.splitbyValue(rt1,b[x]);
      ans-=(1LL*lft.bst[p.first].sz*b[x]+lft.bst[p.second].sm);
      rt1=lft.join(p.first,p.second);
       rt2=rgt.erase(rt2,b[x]);
       b[x]=y;
      p=lft.splitbyValue(rt1,b[x]);
      ans+=(1LL*lft.bst[p.first].sz*b[x]+lft.bst[p.second].sm);
      rt1=lft.join(p.first,p.second);
       rt2=rgt.add(rt2,b[x]);
     }
    cout<<ans<<'\n';
  }
     return 0;
}