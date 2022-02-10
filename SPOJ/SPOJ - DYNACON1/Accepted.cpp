/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-09-30 17:15:35                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 160                                        memory_used (MB): 8.3                             
*  problem: https://vjudge.net/problem/SPOJ-DYNACON1
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
const int N=1e6;
/*
https://courses.csail.mit.edu/6.851/spring12/scribe/L19.pdf
https://www.cnblogs.com/flashhu/p/9498517.html
https://github.com/brunomaletta/Biblioteca/blob/master/Codigo/Grafos/LCT/lct-vertice.cpp
https://codeforces.com/blog/entry/75885
https://github.com/kzvd4729/Tmp/blob/master/lct

represented tree: the actual tree. tree we want to
represent. actual tree are forest of some rooted trees.
like dsu tree.

preferred child: u is called preferred child of v if
last accessed node in v's subtree is in u's subtree.
preferred child can be null if v is last accessed node
or v has no accessed node.

preferred edge: edge between node and preferred child.

preferred path: continuous path where each edge is
preferred edge. preferred path can be a single node.
a tree will have many preferred path. each preferred
path is node disjoint and every node is in exactly one
preferred path.

splay tree: splay trees represent
preferred path. one splay tree for each path. splay
trees are balanced binary search tree where nodes are 
keyed by their depth in actual tree.

path-parent pointer: path parent pointer connects two
splay trees. path parent pointer is stored in the root
of splay tree and points to parent of the topmost
(lowest depth) node of preferred path. so a path parent
pointer is an edge of represented tree which is not
preferred.

splay(v): v becomes the root of the splay tree which 
represents preferred path including v.

access(v): when node v is accessed path from root to v
(in the represented tree) becomes preferred. some
preferred paths also changes. splay tree is used to 
handle this operation. after access(v), v becomes the
root of the splay tree which represents the preferred 
path from root to v. we make v root of the splay just
for convenience.

findRoot(v): access(v). now v is the root. lowest depth
node is the root. lets call it r. after finding r we
have to access r. because r can be in liner depth. 
access(r) guarantee amortized log complexity.

pathAggregate(v): access(v). now do any operation on
path root to v.

*/
struct node
{
  int p,ch[2];
  long val,sub;
  bool rev;
  int sz;
  long lazy;
  node(){}
  node(int v):p(-1),val(v),sub(v),rev(0),sz(1),lazy(0){
      ch[0]=ch[1]=-1;
  }
};
node t[N+2];
void prop(int x)
{
  if(t[x].lazy)
  {
    t[x].val+=t[x].lazy,t[x].sub+=t[x].lazy*t[x].sz;
    if(t[x].ch[0]+1)t[t[x].ch[0]].lazy+=t[x].lazy;
    if(t[x].ch[1]+1)t[t[x].ch[1]].lazy+=t[x].lazy;
  }
  if(t[x].rev)
  {
    swap(t[x].ch[0],t[x].ch[1]);
    if(t[x].ch[0]+1)t[t[x].ch[0]].rev^=1;
    if(t[x].ch[1]+1)t[t[x].ch[1]].rev^=1;
  }
  t[x].lazy=0,t[x].rev=0;
}
void update(int x)
{
  t[x].sz=1,t[x].sub=t[x].val;
  for(int i=0;i<2;i++)
  {
    if(t[x].ch[i]+1==0)continue;
    prop(t[x].ch[i]);
    t[x].sz+=t[t[x].ch[i]].sz;
    t[x].sub+=t[t[x].ch[i]].sub;
  }
}
bool is_root(int x)
{
  return (t[x].p==-1)||((t[t[x].p].ch[0]!=x)&&(t[t[x].p].ch[1]!=x));
}
void rotate(int x)
{
  int p=t[x].p,pp=t[p].p;
  if(!is_root(p))t[pp].ch[t[pp].ch[1]==p]=x;
  bool d=t[p].ch[0]==x;
  t[p].ch[!d]=t[x].ch[d],t[x].ch[d]=p;
  if(t[p].ch[!d]+1)t[t[p].ch[!d]].p=p;
  t[x].p=pp,t[p].p=x;
  update(p),update(x);
}
int splay(int x)
{
  while(!is_root(x))
  {
    int p=t[x].p,pp=t[p].p;
    if(!is_root(p))prop(pp);
    prop(p),prop(x);
    if(!is_root(p))rotate((t[pp].ch[0]==p)^(t[p].ch[0]==x)?x:p);
    rotate(x);
  }
  return prop(x), x;
}
int access(int v)
{
  int last=-1;
  for(int w=v;w+1;update(last=w),splay(v),w=t[v].p)
    splay(w),t[w].ch[1]=(last==-1?-1:v);
  return last;
}
void make_tree(int v,int w){t[v]=node(w);}
int find_root(int v)
{
  access(v),prop(v);
  while (t[v].ch[0]+1)v=t[v].ch[0],prop(v);
  return splay(v);
}
bool connected(int v,int w)
{
  access(v),access(w);
  return v==w?true:t[v].p!=-1;
}
void rootify(int v)
{
  access(v);
  t[v].rev ^= 1;
}
long query(int v,int w)
{
  rootify(w),access(v);
  return t[v].sub;
}
void update(int v,int w,int x)
{
  rootify(w),access(v);
  t[v].lazy+=x;
}
void link(int v,int w)
{
  rootify(w);
  t[w].p=v;
}
void cut(int v,int w)
{
  rootify(w),access(v);
  t[v].ch[0]=t[t[v].ch[0]].p=-1;
}
int lca(int v,int w)
{
  access(v);
  return access(w);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;

  for(int i=1;i<=n;i++)make_tree(i,0);
  for(int i=1;i<=q;i++)
  {
    string s;cin>>s;
    if(s=="add")
    {
      int a,b;cin>>a>>b;
      link(a,b);
    }
    else if(s=="rem")
    {
      int a,b;cin>>a>>b;
      cut(a,b);
    }
    else
    {
      int a,b;cin>>a>>b;
      if(connected(a,b))cout<<"YES\n";
      else cout<<"NO\n";
    }
  }
  return 0;
}