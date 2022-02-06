/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/15/2020 18:16                        
*  solution_verdict: Memory limit exceeded on test 4         language: GNU C++14                               
*  run_time: 186 ms                                          memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/555/problem/E
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=2e5,inf=1e9;
vector<int>adj[N+2],tree[N+2];//rooted tree
vector<pair<int,int> >br;
vector<int>bkadj[N+2];//edges doesn't belong to the tree(end nodes are in a chain)
int vis[N+2],lev[N+2];
void dfs(int node,int par,int lv)
{
  vis[node]=1,lev[node]=lv;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(vis[x])
    {
      bkadj[node].push_back(x);
      bkadj[x].push_back(node);
    }
    else
    {
      tree[node].push_back(x);
      tree[x].push_back(node);
      dfs(x,node,lv+1);
    }
  }
}
set<pair<int,int> >st;
int bridge(int node,int par)
{
  int mn=1e9;
  for(auto x:bkadj[node])
    mn=min(mn,lev[x]);
  for(auto x:tree[node])
  {
    if(x==par)continue;
    mn=min(mn,bridge(x,node));
  }
  if(mn>=lev[node]&&par!=-1)
  {
    st.insert({par,node}),st.insert({node,par});
    br.push_back({par,node});
  }
  return mn;
}
int par[N+2];
int get(int x)
{
  if(par[x]==x)return x;
  return par[x]=get(par[x]);
}
int com[N+2];
void dfs(int node,int c)
{
  com[node]=c;
  for(auto x:adj[node])
  {
    if(com[x])continue;
    if(st.find({node,x})!=st.end())continue;
    dfs(x,c);
  }
}
int ent[N+2],ext[N+2],tim;
void timing(int node,int par)
{
  ent[node]=++tim;
  for(auto x:adj[node])
    if(x!=par)timing(x,node);
  ext[node]=tim;
}
int sp[N+2][20+2],an[N+2][20+2];
void build(int n)
{
  //for(int i=1;i<=n;i++)sp[i][0]=aa[i],an[i][0]=aa[i];//array
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1],an[i][j]=an[i][j-1];
      if((i+(1<<(j-1)))<=n)
      {
        sp[i][j]=min(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
        an[i][j]=max(an[i][j-1],an[i+(1<<(j-1))][j-1]);
      }
    }
  }
}
int getMin(int lt,int rt)
{
  //if(rt<lt)return 1e9;
  int dg=31-__builtin_clz(rt-lt+1);
  return min(sp[lt][dg],sp[rt-(1<<dg)+1][dg]);
}
int getMax(int lt,int rt)
{
  //if(rt<lt)return 1e9;
  int dg=31-__builtin_clz(rt-lt+1);
  return max(an[lt][dg],an[rt-(1<<dg)+1][dg]); 
}
void no()
{
  cout<<"No"<<endl;exit(0);
}
int xx[N+2],yy[N+2];int f[N+2],g[N+2];
void ck(int node,int par)
{
  vis[node]=1;
  for(auto x:adj[node])if(x!=par)ck(x,node);
  if(par==-1)return ;
  if(getMin(ent[node],ext[node])<ent[node])f[node]=1;
  if(getMax(ent[node],ext[node])>ext[node])f[node]=1;
}
void bk(int node,int par)
{
  vis[node]=1;
  for(auto x:adj[node])if(x!=par)bk(x,node);
  if(par==-1)return ;
  if(getMin(ent[node],ext[node])<ent[node])g[node]=1;
  if(getMax(ent[node],ext[node])>ext[node])g[node]=1;
  if(f[node]&&g[node])no();
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,q;cin>>n>>m>>q;
  for(int i=1;i<=n;i++)par[i]=i;vector<pair<int,int> >ed;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;int a=get(u),b=get(v);if(u!=v)par[u]=v;
    adj[u].push_back(v);adj[v].push_back(u);
    ed.push_back({u,v});
  }
  for(int i=1;i<=n;i++)
  {
    if(vis[i]==0)dfs(i,-1,0),bridge(i,-1);
  }
  //for(auto x:br)cout<<x.first<<" --> "<<x.second<<endl;
  int cnt=0;
  for(int i=1;i<=n;i++)if(com[i]==0)dfs(i,++cnt);
  //for(int i=1;i<=n;i++)cout<<com[i]<<" ";cout<<endl;
  for(int i=1;i<=n;i++)adj[i].clear();
   for(auto x:ed)
  {
    if(com[x.first]==com[x.second])continue;
    adj[x.first].push_back(x.second);adj[x.second].push_back(x.first);
  }
  for(int i=1;i<=cnt;i++)
    if(ent[i]==0)timing(i,-1);
    for(int i=1;i<=q;i++)
  {
    cin>>xx[i]>>yy[i];if(get(xx[i])!=get(yy[i]))no();
    xx[i]=com[xx[i]],yy[i]=com[yy[i]];
    xx[i]=ent[xx[i]],yy[i]=ent[yy[i]];
  }
  for(int i=1;i<=n;i++)sp[i][0]=inf,an[i][0]=-inf;
  for(int i=1;i<=cnt;i++)
  {
    sp[xx[i]][0]=min(sp[xx[i]][0],yy[i]);
    an[xx[i]][0]=max(an[xx[i]][0],yy[i]);
  }
  build(cnt);memset(vis,0,sizeof vis);
  for(int i=1;i<=cnt;i++)
  {
    if(vis[i])continue;
    ck(i,-1);
  }
   for(int i=1;i<=n;i++)sp[i][0]=inf,an[i][0]=-inf;
  for(int i=1;i<=cnt;i++)
  {
    sp[yy[i]][0]=min(sp[yy[i]][0],xx[i]);
    an[yy[i]][0]=max(an[yy[i]][0],xx[i]);
  }
  build(cnt);memset(vis,0,sizeof vis);
  for(int i=1;i<=cnt;i++)
  {
    if(vis[i])continue;
    bk(i,-1);
  }
  cout<<"Yes"<<endl;
   return 0;
}