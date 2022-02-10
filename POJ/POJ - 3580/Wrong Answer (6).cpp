/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-09-28 20:52:12                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-3580
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
//#include<unordered_map>
//#include<unordered_set>
//#include<chrono>
#include<stack>
#include<deque>
//#include<random>
#define long long long 
using namespace std;
const long N=2e5;
const long inf=1e18;

void tle(){for(int i=1; ;i++);}

long tr;//treap size
struct treap
{
  long lt,rt,dt,pri,sz,lzad,mn;
  long lzrv;//lazy for reverse

}bst[N+2];
void init()//set for invalid index
{
  bst[0]={0,0,0,0,0,0,inf,0};//minimum should be infinite
}
void tooLazy(long nd)//lazy propagation
{
  if(!nd)return ;
  long l=bst[nd].lt,r=bst[nd].rt;

  bst[nd].dt+=bst[nd].lzad;
  bst[nd].mn+=bst[nd].lzad;

  if(l)bst[l].lzad+=bst[nd].lzad;
  if(r)bst[r].lzad+=bst[nd].lzad;
  bst[nd].lzad=0;

  if(bst[nd].lzrv==0)return ;
  swap(bst[nd].lt,bst[nd].rt);
  if(l)bst[l].lzrv^=1;if(r)bst[r].lzrv^=1;
  bst[nd].lzrv=0;
}
void cal(long nd)
{
  if(!nd)return ;tooLazy(nd);
  long l=bst[nd].lt,r=bst[nd].rt;
  bst[nd].sz=bst[l].sz+bst[r].sz+1;
  bst[nd].mn=min(min(bst[nd].dt,bst[l].mn),bst[r].mn);
}
pair<long,long>splitbySize(long node,long ss)
{
  tooLazy(node);
  if(!node)return {0,0};pair<long,long>p;
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
//lt and rt are bst and max element of lt <= minimum of rt
long join(long lt,long rt)
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
long root=0;
long createNode(long x)
{
  bst[++tr]={0,0,x,rand(),1,0,x,0};
  return tr;
}
void add(long x,long y,long d)
{
  //assert(d>=0);
  pair<long,long>p1=splitbySize(root,x-1);
  pair<long,long>p2=splitbySize(p1.second,y-x+1);
  bst[p2.first].lzad+=d;

  root=join(p2.first,p2.second);
  root=join(p1.first,root);
}
void reverse(long x,long y)
{
  pair<long,long>p1=splitbySize(root,x-1);
  pair<long,long>p2=splitbySize(p1.second,y-x+1);
  bst[p2.first].lzrv^=1;

  root=join(p2.first,p2.second);
  root=join(p1.first,root);
}
void revolve(long x,long y,long t)
{
  //assert(t<=(y-x+1));
  //if(t<0||t>y-x+1)tle();
  t=(t%(y-x+1)+y-x+1)%(y-x+1);
  if(t==0)return;
  pair<long,long>p1=splitbySize(root,x-1);
  pair<long,long>p2=splitbySize(p1.second,y-x+1);
  pair<long,long>p3=splitbySize(p2.first,y-x+1-t);

  root=join(p3.second,p3.first);
  root=join(root,p2.second);
  root=join(p1.first,root);
}
void insert(long x,long vl)
{
  pair<long,long>p=splitbySize(root,x);
  root=join(p.first,createNode(vl));
  root=join(root,p.second);
}
void del(long x)
{
  pair<long,long>p1=splitbySize(root,x-1);
  pair<long,long>p2=splitbySize(p1.second,1);

  root=join(p1.first,p2.second);
}
long mini(long x,long y)
{
  pair<long,long>p1=splitbySize(root,x-1);
  pair<long,long>p2=splitbySize(p1.second,y-x+1);

  long ret=bst[p2.first].mn;
  if(bst[p2.first].lzad)tle();

  root=join(p2.first,p2.second);
  root=join(p1.first,root);

  return ret;
}
int main()  
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  init();//assert(0);

  long n;cin>>n;
  for(long i=1;i<=n;i++)
  {
    long x;cin>>x;
    insert(i-1,x);
  }
  long m;cin>>m;
  while(m--)
  {
    string s;cin>>s;
    if(s=="ADD")
    {
      long x,y,d;cin>>x>>y>>d;
      add(x,y,d);
    }
    else if(s=="REVERSE")
    {
      long x,y;cin>>x>>y;
      reverse(x,y);
    }
    else if(s=="REVOLVE")
    {
      long x,y,t;cin>>x>>y>>t;
      revolve(x,y,t);
    }
    else if(s=="INSERT")
    {
      long x,p;cin>>x>>p;
      insert(x,p);
    }
    else if(s=="DELETE")
    {
      long x;cin>>x;
      del(x);
    }
    else 
    {
      long x,y;cin>>x>>y;
      cout<<mini(x,y)<<endl;
    }
  }
  return 0;
}