/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/19/2020 23:47                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 51000 KB                             
*  problem: https://codeforces.com/contest/983/problem/E
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
const int N=2e5,inf=1e9;
int lev[N+2],sp[N+2][20+2],ps[N+2][20+2],ent[N+2],ext[N+2],tim;
vector<int>adj[N+2],ph[N+2];
void reckon(int n,int p,int h)
{
  sp[n][0]=p;lev[n]=h;ent[n]=++tim;
  for(auto x:adj[n])
    if(x!=p)reckon(x,n,h+1);
  ext[n]=tim;
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
int dfs(int n,int p)
{
  int l=inf,nd;
  for(auto x:adj[n])
  {
    if(x==p)continue;int u=dfs(x,n);
    if(u==-1)continue;
     if(lev[u]<l)l=lev[u],nd=u;
  }
  for(auto x:ph[n])
  {
    int u=lca(n,x);
    if(lev[u]<l)l=lev[u],nd=u;
  }
  if(l>=lev[n])nd=-1;return ps[n][0]=nd;
}
int raise(int u,int lv,int &d)
{
  d=0;
  for(int i=20;i>=0;i--)
  {
    if(ps[u][i]==-1)continue;
    if(lev[ps[u][i]]>lv)
      d+=(1<<i),u=ps[u][i];
  }
  return u;
}
vector<vector<int> >vv[N+2];
int ans[N+2],lz[N+2],fl[N+2];
multiset<int>bit[N+2];
void add(int id,int x)
{
  for( ;id>0;id-=id&-id)bit[id].insert(x);
}
void del(int id,int x)
{
  for( ;id>0;id-=id&-id)bit[id].erase(bit[id].find(x));
}
int get(int id,int x)
{
  int ret=1e9;
  for( ;id<=N;id+=id&-id)
  {
    auto it=bit[id].lower_bound(x);
    if(it!=bit[id].end())ret=min(ret,*it);
  }
  return ret;
}
void solve(int n)
{
  for(int i=1;i<=n;i++)
  {
    sort(vv[i].begin(),vv[i].end(),[&](vector<int>a,vector<int>b){
      int u=ent[a[0]],v=ent[b[0]];
      if(a.size()==3)u=ext[a[0]];
      if(b.size()==3)v=ext[b[0]];
      if(u==v)return a.size()<b.size();
      return u<v;
    });
    for(auto x:vv[i])
    {
      if(x.size()==2)add(ent[x[0]],ent[x[1]]);
      else
      {
        int g=get(ent[x[0]],ent[x[1]]);
        fl[x[2]]|=(g<=ext[x[1]]);
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=2;i<=n;i++)
  {
    int x;cin>>x;
    adj[i].push_back(x);adj[x].push_back(i);
  }
  reckon(1,-1,0);sparse(n);
  int m;cin>>m;
  while(m--)
  {
    int u,v;cin>>u>>v;
    ph[u].push_back(v);ph[v].push_back(u);
    int lc=lca(u,v);vv[lc].push_back({u,v});vv[lc].push_back({v,u});
  }
  dfs(1,-1);
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      ps[i][j]=ps[i][j-1];
      if(ps[i][j-1]!=-1)
        ps[i][j]=ps[ps[i][j-1]][j-1];
    }
  }
  //for(int i=1;i<=n;i++)cout<<i<<" "<<ps[i][0]<<endl;
  int q;cin>>q;
  for(int i=1;i<=q;i++)
  {
    int u,v;cin>>u>>v;
    if(lev[u]>lev[v])swap(u,v);
    if(lca(u,v)==u)
    {
      int d;v=raise(v,lev[u],d);
      if(ps[v][0]==-1)ans[i]=-1;
      else ans[i]=d+1;
    }
    else
    {
      int d1,d2,lc=lca(u,v);u=raise(u,lev[lc],d1),v=raise(v,lev[lc],d2);
      if(ps[u][0]==-1||ps[v][0]==-1){ans[i]=-1;continue;}
      ans[i]=d1+d2;lz[i]=1;
      vv[lc].push_back({u,v,i});vv[lc].push_back({v,u,i});
    }
  }
  solve(n);
  for(int i=1;i<=q;i++)
  {
    if(lz[i])
    {
      if(fl[i])ans[i]++;else ans[i]+=2;
    }
    cout<<ans[i]<<'\n';
  }
  return 0;
}