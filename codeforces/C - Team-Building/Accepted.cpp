/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/08/2020 22:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1278 ms                                         memory_used: 81300 KB                             
*  problem: https://codeforces.com/contest/1444/problem/C
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
int gr[N+2],cl[N+2],bad[N+2],rt[N+2];
vector<pair<int,int> >ls[N+2];
vector<int>ad[N+2],df[N+2],vv[N+2];
void dfs(int nd,int c,int r)
{
  rt[nd]=r;
  if(cl[nd]!=-1)
  {
    if(cl[nd]!=c)bad[gr[nd]]=1;
    return ;
  }
  cl[nd]=c;
  for(auto x:ad[nd])dfs(x,c^1,r);
}
pair<int,int>par[N+2];vector<int>bf;
pair<int,int>find(int x)
{
  if(x!=par[x].first)
  {
    int pr=par[x].second;par[x]=find(par[x].first);
    bf.push_back(x);par[x].second^=pr;
  }
  return par[x];
}
//return false if adding this edge cause odd cycle
bool add(int a,int b)
{
  pair<int,int>pa=find(a),pb=find(b);
  if(pa.first==pb.first)return pa.second!=pb.second;
  par[pb.first]={pa.first,pa.second^pb.second^1};
  bf.push_back(pb.first);
  return true;
}
void clear()
{
  for(auto x:bf)par[x]={x,0};
  bf.clear();
}
void init()
{
  for(int i=1;i<=N;i++)par[i]={i,0};
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=n;i++)cin>>gr[i],vv[gr[i]].push_back(i);
   for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    if(gr[u]==gr[v])ad[u].push_back(v),ad[v].push_back(u);
    else df[u].push_back(v),df[v].push_back(u);
  }
  for(int i=1;i<=n;i++)cl[i]=-1;
  for(int i=1;i<=n;i++)
  {
    if(cl[i]==-1)dfs(i,0,i);
  }
  int cnt=0;
  for(int i=1;i<=k;i++)cnt+=bad[i];
  long ans=0;init();
  for(int i=1;i<=k;i++)
  {
    if(bad[i])continue;set<int>un;
    for(auto u:vv[i])
    {
      for(auto v:df[u])
      {
        if(bad[gr[v]])continue;
        ls[gr[v]].push_back({u,v});
        un.insert(gr[v]);
      }
    }
    int good=k-cnt-1;
    for(auto g:un)
    {
      set<int>bl;int f=0;
      for(auto x:ls[g])
      {
        bl.insert(rt[x.first]);
        bl.insert(rt[x.second]);
      }
      for(auto x:bl)
      {
        if((int)ad[x].size())add(x,ad[x][0]);
      }
      for(auto x:ls[g])
      {
        int a=rt[x.first],b=rt[x.second];
        if(cl[x.first]==1)a=ad[a][0];
        if(cl[x.second]==1)b=ad[b][0];
        f|=(!add(a,b));
      }
      clear();good-=f;ls[g].clear();
    }
    ans+=good;
  }
  cout<<ans/2<<endl;
  return 0;
}