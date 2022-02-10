/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-09-28 21:29:35                      
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
const int N=2e5;
const int inf=2e9;

void tle(){for(int i=1; ;i++);}

int tr;//treap size
struct treap
{
  int lt,rt;int dt,pri,sz,lzad,mn;
  int lzrv;//lazy for reverse

}bst[N+2];
void init()//set for invalid index
{
  bst[0]={0,0,0,0,0,0,inf,0};//minimum should be infinite
}
void tooLazy(int nd)//lazy propagation
{
  if(!nd)return ;
  if(bst[nd].lzad==0&&bst[nd].lzrv==0)return ;
  int l=bst[nd].lt,r=bst[nd].rt;

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
void cal(int nd)
{
  if(!nd)return ;tooLazy(nd);
  int l=bst[nd].lt,r=bst[nd].rt;
  bst[nd].sz=bst[l].sz+bst[r].sz+1;
  bst[nd].mn=min(min(bst[nd].dt,bst[l].mn),bst[r].mn);
}
pair<int,int>splitbySize(int node,int ss)
{
  tooLazy(node);
  tooLazy(bst[node].lt);tooLazy(bst[node].rt);
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
//lt and rt are bst and max element of lt <= minimum of rt
int join(int lt,int rt)
{
  tooLazy(lt);tooLazy(rt);
  //tooLazy(bst[lt].lt);tooLazy(bst[lt].rt);
  //tooLazy(bst[rt].lt);tooLazy(bst[rt].rt);

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
int root=0;
int createNode(int x)
{
  bst[++tr]={0,0,x,rand(),1,0,x,0};
  return tr;
}
void add(int x,int y,int d)
{
  //assert(d>=0);
  pair<int,int>p1=splitbySize(root,x-1);
  pair<int,int>p2=splitbySize(p1.second,y-x+1);
  bst[p2.first].lzad+=d;

  root=join(p2.first,p2.second);
  root=join(p1.first,root);
}
void reverse(int x,int y)
{
  pair<int,int>p1=splitbySize(root,x-1);
  pair<int,int>p2=splitbySize(p1.second,y-x+1);
  bst[p2.first].lzrv^=1;

  root=join(p2.first,p2.second);
  root=join(p1.first,root);
}
void revolve(int x,int y,int t)
{
  //assert(t<=(y-x+1));
  //if(t<0||t>y-x+1)tle();
  t=(t%(y-x+1)+y-x+1)%(y-x+1);
  if(t==0)return;
  pair<int,int>p1=splitbySize(root,x-1);
  pair<int,int>p2=splitbySize(p1.second,y-x+1);
  pair<int,int>p3=splitbySize(p2.first,y-x+1-t);

  root=join(p3.second,p3.first);
  root=join(root,p2.second);
  root=join(p1.first,root);
}
void insert(int x,int vl)
{
  pair<int,int>p=splitbySize(root,x);
  root=join(p.first,createNode(vl));
  root=join(root,p.second);
}
void del(int x)
{
  pair<int,int>p1=splitbySize(root,x-1);
  pair<int,int>p2=splitbySize(p1.second,1);

  root=join(p1.first,p2.second);
}
int mini(int x,int y)
{
  pair<int,int>p1=splitbySize(root,x-1);
  pair<int,int>p2=splitbySize(p1.second,y-x+1);

  int ret=bst[p2.first].mn;
  if(bst[p2.first].lzad)tle();

  root=join(p2.first,p2.second);
  root=join(p1.first,root);

  return ret;
}
void print()
{
  int sz=bst[root].sz;

  for(int i=1;i<=sz;i++)
  {
    pair<int,int>p1=splitbySize(root,i-1);
    pair<int,int>p2=splitbySize(p1.second,1);
    cout<<bst[p2.first].dt<<" ";

    root=join(p2.first,p2.second);
    root=join(p1.first,root);
  }
  cout<<endl;
}
int main()  
{
  //freopen("inp.txt","r",stdin);
  //freopen("opt.txt","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
  init();//assert(0);

  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    insert(i-1,x);
  }
  //print();
  int m;cin>>m;
  while(m--)
  {
    string s;cin>>s;
    if(s=="ADD")
    {
      int x,y,d;cin>>x>>y>>d;
      add(x,y,d);
    }
    else if(s=="REVERSE")
    {
      int x,y;cin>>x>>y;
      reverse(x,y);
    }
    else if(s=="REVOLVE")
    {
      int x,y,t;cin>>x>>y>>t;
      revolve(x,y,t);
    }
    else if(s=="INSERT")
    {
      int x,p;cin>>x>>p;
      insert(x,p);
    }
    else if(s=="DELETE")
    {
      int x;cin>>x;
      del(x);
    }
    else 
    {
      int x,y;cin>>x>>y;
      cout<<mini(x,y)<<'\n';
    }
    //print();
  }
  return 0;
}