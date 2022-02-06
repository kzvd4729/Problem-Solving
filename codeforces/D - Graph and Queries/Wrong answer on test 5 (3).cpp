/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/29/2020 20:43                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 43200 KB                             
*  problem: https://codeforces.com/contest/1416/problem/D
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
int par[N+2],a[N+2],u[N+2],v[N+2],ty[N+2],nd[N+2];
int vs[N+2],sz[N+2],xx[N+2];
set<int>st[N+2],ad[N+2];
int find(int x)
{
  if(x==par[x])return x;
  return par[x]=find(par[x]);
}
int add(int u,int v)
{
  int p1=find(u),p2=find(v);
  if(p1==p2)return 0;
   ad[u].insert(v);ad[v].insert(u);
   if(sz[p1]<sz[p2]){par[p1]=p2;return u;}
  else {par[p2]=p1;return v;}
}
void dfs(int nd,int rt)
{
  st[rt].insert(a[nd]);vs[nd]=1;par[nd]=rt;
  for(auto x:ad[nd])
    if(vs[x]==0)dfs(x,rt);
}
int bad[N+2];
void dds(int nd,int pr,int rt,int prt)
{
  par[nd]=rt;
  if(bad[a[nd]]==0)st[rt].insert(a[nd]),st[prt].erase(a[nd]);
  for(auto x:ad[nd])if(x!=pr)dds(x,nd,rt,prt);
}
int main()  
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,q;cin>>n>>m>>q;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=m;i++)
  {
    cin>>u[i]>>v[i];
  }
  for(int i=1;i<=q;i++)
  {
    cin>>ty[i]>>nd[i];
    if(ty[i]==2)vs[nd[i]]=1;
  }
  for(int i=1;i<=n;i++)par[i]=i,sz[i]=1;
  for(int i=1;i<=m;i++)
  {
    if(vs[i])continue;
    add(u[i],v[i]);
  }
  for(int i=q;i>=1;i--)
  {
    if(ty[i]==1)continue;
    xx[i]=add(u[nd[i]],v[nd[i]]);
  }
  for(int i=1;i<=n;i++)vs[i]=0;
  for(int i=1;i<=n;i++)
  {
    if(vs[i])continue;dfs(i,i);
  }
  //for(int i=1;i<=n;i++)cout<<par[i]<<" ";cout<<endl;
  for(int i=1;i<=q;i++)
  {
    if(ty[i]==1)
    {
      int rt=par[nd[i]],x=0;
      while(st[rt].size())
      {
        x=*st[rt].rbegin();st[rt].erase(x);
        if(bad[x]==0)break;
        else x=0;
      }
      if(x&&bad[x])assert(0);
      cout<<x<<'\n';bad[x]=1;
    }
    else
    {
      int nm=nd[i];
      if(xx[i]==0)continue;
      ad[u[nm]].erase(v[nm]);ad[v[nm]].erase(u[nm]);
       if(xx[i]==u[nm])dds(u[nm],-1,u[nm],par[u[nm]]);
      else dds(v[nm],-1,v[nm],par[v[nm]]);
    }
    //for(int i=1;i<=n;i++)cout<<par[i]<<" ";cout<<endl;
  }
  return 0;
}