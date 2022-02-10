/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-10-07 22:46:11                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-QTREE4
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

int tot,mark[N+2],sz[N+2];
vector<int>ad[N+2],cs[N+2],dr[N+2],v[N+2];
void reckon(int nd,int pr)
{
  tot++;sz[nd]=1;
  for(auto x:ad[nd])
  {
    if(mark[x]||x==pr)continue;
    reckon(x,nd);sz[nd]+=sz[x];
  }
}
int findCenter(int nd,int pr)
{
  for(auto x:ad[nd])
  {
    if(x==pr||mark[x])continue;
    if(sz[x]>tot/2)return findCenter(x,nd);
  }
  return nd;
}
int par[N+2],rt;
void centroid(int nd,int pr)
{
  tot=0;reckon(nd,-1);
  int center=findCenter(nd,-1);
  mark[center]=1;if(pr==-1)rt=center;
  for(auto x:ad[center])
  {
    if(mark[x])continue;
    par[x]=center;dr[center].push_back(x);
    centroid(x,center);
  }
}
int lev[N+2],sp[N+2][21],ds[N+2];
void reckon(int n,int p,int h,int d)
{
  sp[n][0]=p;lev[n]=h;
  int id=0;ds[n]=d;
  for(auto x:ad[n])
  {
    if(x!=p)reckon(x,n,h+1,d+cs[n][id]);
    id++;
  }
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
int ent[N+2],tim;
void timing(int nd)
{
  ent[nd]=++tim;
  for(auto x:dr[nd])
    timing(x);
}
int dist(int u,int v)
{
  int lc=lca(u,v);
  return ds[u]+ds[v]-2*ds[lc];
}
vector<multiset<int> >s[N+2];
int white;multiset<int>st[N+2],ov;
void makeWhite(int nd)
{
  white++;
  while(par[nd])
  {
    int p=par[nd];
    int nm=upper_bound(v[p].begin(),v[p].end(),ent[nd])-v[p].begin();
    nm--;

    if(st[p].size()>=2)
    {
      auto it=st[p].begin();it++;
      ov.erase(ov.find(*st[p].begin()+*it));
    }

    if(s[p][nm].size())
    {
      int mx=*s[p][nm].rbegin();
      st[p].erase(st[p].find(mx));
    }
    s[p][nm].insert(dist(p,nd));
    st[p].insert(*s[p][nm].rbegin());

    if(st[p].size()>=2)
    {
      auto it=st[p].begin();it++;
      ov.insert(*st[p].begin()+*it);
    }
    nd=p;
  }
}
void makeBlack(int nd)
{
  white--;
  while(par[nd])
  {
    int p=par[nd];
    int nm=upper_bound(v[p].begin(),v[p].end(),ent[nd])-v[p].begin();
    nm--;

    if(st[p].size()>=2)
    {
      auto it=st[p].begin();it++;
      ov.erase(ov.find(*st[p].begin()+*it));
    }

    if(s[p][nm].size())
    {
      int mx=*s[p][nm].rbegin();
      st[p].erase(st[p].find(mx));
    }
    s[p][nm].erase(s[p][nm].find(dist(p,nd)));
    if(s[p][nm].size())st[p].insert(*s[p][nm].rbegin());

    if(st[p].size()>=2)
    {
      auto it=st[p].begin();it++;
      ov.insert(*st[p].begin()+*it);
    }
    nd=p;
  }
}
int cl[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    ad[u].push_back(v);ad[v].push_back(u);
    cs[u].push_back(w);cs[v].push_back(w);
  }
  centroid(1,-1);reckon(1,-1,0,0);sparse(n);

  timing(rt);
  for(int i=1;i<=n;i++)
  {
    for(auto x:dr[i])v[i].push_back(ent[x]);
    s[i].resize(dr[i].size());
  }
  for(int i=1;i<=n;i++)makeWhite(i);

  int q;cin>>q;
  //cout<<"*"<<q<<endl;
  while(q--)
  {
    char c;cin>>c;
    if(c=='A')
    {
      if(white==0)cout<<"They have disappeared.\n";
      else if(ov.size())cout<<*ov.rbegin()<<'\n';
      else cout<<"0\n";
    }
    else
    {
      int nd;cin>>nd;
      if(cl[nd]==0)makeBlack(nd);
      else makeWhite(nd);

      cl[nd]^=1;
    }
  }
  return 0;
}