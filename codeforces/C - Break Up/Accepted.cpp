/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/09/2020 19:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 421 ms                                          memory_used: 53900 KB                             
*  problem: https://codeforces.com/contest/700/problem/C
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
const int N=1e6,inf=2e9+2;
vector<pair<int,int> >ad[N+2],tree[N+2];
int br[N+2];
vector<int>bkad[N+2];
int vis[N+2],lev[N+2];
void clear(int n,int m)
{
  for(int i=1;i<=n;i++)
  {
    tree[i].clear(),bkad[i].clear();
    vis[i]=0,lev[i]=0;
  }
  for(int i=1;i<=m;i++)br[i]=0;
}
void dfs(int node,int par,int lv)
{
  vis[node]=1,lev[node]=lv;
  for(auto z:ad[node])
  {
    int x=z.first;
    if(x==par)continue;
    if(vis[x])
    {
      bkad[node].push_back(x);
      bkad[x].push_back(node);
    }
    else
    {
      tree[node].push_back({x,z.second});
      tree[x].push_back({node,z.second});
      dfs(x,node,lv+1);
    }
  }
}
int bridge(int node,int par,int nm)
{
  int mn=1e9;
  for(auto x:bkad[node])
    mn=min(mn,lev[x]);
  for(auto x:tree[node])
  {
    if(x.first==par)continue;
    mn=min(mn,bridge(x.first,node,x.second));
  }
  if(mn>=lev[node]&&par!=-1)br[nm]=1;
  return mn;
}
vector<int>pth;int vs[N+2];
bool find(int nd,int tr)
{
  if(nd==tr)return true;
  vs[nd]=1;
  for(auto x:ad[nd])
  {
    if(vs[x.first])continue;
    pth.push_back(x.second);
    if(find(x.first,tr))return true;
    pth.pop_back();
  }
  return false;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  int s,t;cin>>s>>t;vector<vector<int> >ed(m+1);
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    ed[i]={u,v,w};
     ad[u].push_back({v,i});
    ad[v].push_back({u,i});
  }
  find(s,t);int ans=inf,one=-1,two=-1;
  if((int)pth.size()==0)cout<<0<<" "<<0<<endl,exit(0);
   vector<int>ok=pth;
  for(auto x:ok)
  {
    int u=ed[x][0],v=ed[x][1];int id=0;
    for(auto z:ad[u])
    {
      if(z.second==x)
      {
        ad[u].erase(ad[u].begin()+id);
        break;
      }
      id++;
    }
    id=0;
    for(auto z:ad[v])
    {
      if(z.second==x)
      {
        ad[v].erase(ad[v].begin()+id);
        break;
      }
      id++;
    }
    pth.clear();for(int i=1;i<=n;i++)vs[i]=0;
    find(s,t);
     if((int)pth.size()==0)
    {
      if(ed[x][2]<ans)ans=ed[x][2],one=x,two=-1;
    }
    dfs(s,-1,0);bridge(s,-1,0);
    for(auto z:pth)
    {
      if(br[z]==0)continue;
      if(ed[x][2]+ed[z][2]<ans)ans=ed[x][2]+ed[z][2],one=x,two=z;
    }
    clear(n,m);
     ad[ed[x][0]].push_back({ed[x][1],x});
    ad[ed[x][1]].push_back({ed[x][0],x});
  }
  if(ans==inf)cout<<-1<<endl;
  else
  {
    cout<<ans<<" ";
    if(two==-1)cout<<1<<" "<<one<<endl;
    else cout<<2<<" "<<one<<" "<<two<<endl;
  }
  return 0;
}