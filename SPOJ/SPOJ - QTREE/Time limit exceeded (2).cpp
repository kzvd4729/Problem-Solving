/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-10-07 20:01:16                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-QTREE
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
const int N=1e6,inf=2e9;

struct node
{
  int p,ch[2];//parent and child;
  long dt,sm;//value of the node and sum of subtree(in splay)
  bool rev;//splay tree operation.
  int sz;//size of the subtree(in splay).
  long lz;//lazy add
  node(){}
  node(int v):p(-1),dt(v),sm(v),rev(0),sz(1),lz(0){
      ch[0]=ch[1]=-1;
  }
};
node t[N+2];
void tooLazy(int x)//lazy propagation
{
  if(t[x].lz)
  {
    t[x].dt+=t[x].lz,t[x].sm+=t[x].lz;
    if(t[x].ch[0]+1)t[t[x].ch[0]].lz+=t[x].lz;
    if(t[x].ch[1]+1)t[t[x].ch[1]].lz+=t[x].lz;
  }
  if(t[x].rev)
  {
    swap(t[x].ch[0],t[x].ch[1]);
    if(t[x].ch[0]+1)t[t[x].ch[0]].rev^=1;
    if(t[x].ch[1]+1)t[t[x].ch[1]].rev^=1;
  }
  t[x].lz=0,t[x].rev=0;
}
void cal(int x)//splay tree operation
{
  t[x].sz=1,t[x].sm=t[x].dt;
  for(int i=0;i<2;i++)
  {
    if(t[x].ch[i]+1==0)continue;
    tooLazy(t[x].ch[i]);
    t[x].sz+=t[t[x].ch[i]].sz;t[x].sm=max(t[x].sm,t[t[x].ch[i]].sm);
  }
}
bool isRoot(int x)
{
  return (t[x].p==-1)||((t[t[x].p].ch[0]!=x)&&(t[t[x].p].ch[1]!=x));
}
void rotate(int x)//splay tree 
{
  int p=t[x].p,pp=t[p].p;
  if(!isRoot(p))t[pp].ch[t[pp].ch[1]==p]=x;
  bool d=t[p].ch[0]==x;
  t[p].ch[!d]=t[x].ch[d],t[x].ch[d]=p;
  if(t[p].ch[!d]+1)t[t[p].ch[!d]].p=p;
  t[x].p=pp,t[p].p=x;cal(p),cal(x);
}
int splay(int x)//splay tree
{
  while(!isRoot(x))
  {
    int p=t[x].p,pp=t[p].p;
    if(!isRoot(p))tooLazy(pp);
    tooLazy(p),tooLazy(x);
    if(!isRoot(p))rotate((t[pp].ch[0]==p)^(t[p].ch[0]==x)?x:p);
    rotate(x);
  }
  return tooLazy(x),x;
}
int access(int v)
{
  int last=-1;
  for(int w=v;w+1;cal(last=w),splay(v),w=t[v].p)
    splay(w),t[w].ch[1]=(last==-1?-1:v);
  return last;
}
void init(int v,int w)
{
  //cout<<v<<" "<<w<<endl;
  t[v]=node(w);
}//node v initialization with value w.
int findRoot(int v)
{
  access(v),tooLazy(v);
  while(t[v].ch[0]+1)v=t[v].ch[0],tooLazy(v);
  return splay(v);
}
bool isConnected(int v,int w)
{
  access(v),access(w);
  return v==w?true:t[v].p!=-1;
}
void makeRoot(int v)
{
  access(v);t[v].rev^=1;
}
long query(int u,int v)//query on path u-v
{
  makeRoot(v),access(u);
  return t[u].sm;
}
void update(int u,int v,int x)//add x to all node in u-v path
{
  makeRoot(v),access(u);
  t[u].lz+=x;
}
void add(int u,int v)//add an edge between u and v.
{
  if(isConnected(u,v))return ;
  makeRoot(v);t[v].p=u;
}
void cut(int u,int v)//cut edge between u and v, given they already have edge.
{
  makeRoot(v),access(u);
  t[u].ch[0]=t[t[u].ch[0]].p=-1;
}
vector<pair<int,int> >ad[N+2];
int cost[N+2],ed[N+2],vl[N+2];
void dfs(int nd,int pr,int cs)
{
  init(nd,cost[cs]);ed[cs]=nd;
  if(pr!=-1)add(pr,nd);vl[nd]=cost[cs];
  for(auto x:ad[nd])
  {
    if(x.first==pr)continue;
    dfs(x.first,nd,x.second);
  }
}
int lev[N+2],sp[N+2][21];
void reckon(int n,int p,int h)
{
  sp[n][0]=p;lev[n]=h;
  for(auto x:ad[n])
    if(x.first!=p)reckon(x.first,n,h+1);
}
void sparse(int n)
{
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if(sp[i][j-1]!=-1)
        sp[i][j]=sp[sp[i][j-1]][j-1];
    }
  }
}
int lca(int u,int v)
{
  if(lev[u]<lev[v])swap(u,v);
  for(int i=20;i>=0;i--)
  {
    if(lev[u]-(1<<i)>=lev[v])
      u=sp[u][i];
  }
  if(u==v)return u;
  for(int i=20;i>=0;i--)
  {
    if(sp[u][i]==sp[v][i])continue;
    u=sp[u][i],v=sp[v][i];
  }
  return sp[u][0];
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  int tc;cin>>tc;
  while(tc--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)ad[i].clear();
    for(int i=1;i<n;i++)
    {
      int u,v,w;cin>>u>>v>>w;cost[i]=w;
      ad[u].push_back({v,i});
      ad[v].push_back({u,i});
    }
    dfs(1,-1,0);string s;reckon(1,-1,0);sparse(n);
    while(cin>>s)
    {
      if(s=="DONE")break;
      int a,b;cin>>a>>b;
      if(s=="CHANGE")
      {
        int nd=ed[a];int pr=vl[nd];
        //cout<<nd<<endl;
        update(nd,nd,b-pr);vl[nd]=b;
      }
      else
      {
        int lc=lca(a,b);//cout<<"*"<<lc<<endl;
        int pr=vl[lc];update(lc,lc,-pr);

        cout<<query(a,b)<<'\n';
        update(lc,lc,pr);
      }
    }
  }
  return 0;
}