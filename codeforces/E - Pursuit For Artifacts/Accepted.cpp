/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/10/2020 00:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 935 ms                                          memory_used: 167900 KB                            
*  problem: https://codeforces.com/contest/652/problem/E
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
const int N=1e6,inf=1e9;
vector<int>ad[N+2],tree[N+2];//rooted tree
vector<pair<int,int> >br;
vector<int>bkad[N+2];//edges doesn't belong to the tree(end nodes are in a chain)
 int vis[N+2],lev[N+2];
void dfs(int node,int par,int lv)
{
  vis[node]=1,lev[node]=lv;
  for(auto x:ad[node])
  {
    if(x==par)continue;
    if(vis[x])
    {
      bkad[node].push_back(x);bkad[x].push_back(node);
    }
    else
    {
      tree[node].push_back(x);tree[x].push_back(node);
      dfs(x,node,lv+1);
    }
  }
}
int bridge(int node,int par)
{
  int mn=1e9;
  for(auto x:bkad[node])mn=min(mn,lev[x]);
  for(auto x:tree[node])
  {
    if(x==par)continue;
    mn=min(mn,bridge(x,node));
  }
  if(mn>=lev[node]&&par!=-1)br.push_back({par,node});
  return mn;
}
vector<int>ab[N+2];map<pair<int,int>,int>mp;
int com[N+2],f[N+2];
void dfs(int nd,int c)
{
  if(com[nd])return ;
  com[nd]=c;int id=-1;
  for(auto x:ad[nd])
  {
    id++;
    if(mp[{nd,x}])continue;
    if(ab[nd][id])f[c]=1;dfs(x,c);
  }
}
int par[N+2],fl[N+2];
vector<pair<int,int> >an[N+2];
void dds(int nd,int pr,int lv,int bl)
{
  lev[nd]=lv;par[nd]=pr;fl[nd]=bl;
  for(auto x:an[nd])
    if(x.first!=pr)dds(x.first,nd,lv+1,x.second);
}
int raise(int a,int b)
{
  int ans=f[a]|f[b];
  if(lev[a]<lev[b])swap(a,b);
  while(lev[a]>lev[b])
  {
    ans|=fl[a];a=par[a];
    ans|=f[a];
  }
  while(a!=b)
  {
    ans|=fl[a];a=par[a];ans|=f[a];
     ans|=fl[b];b=par[b];ans|=f[b];
  }
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;assert(m>=n-1);
  vector<vector<int> >ed;
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    ad[u].push_back(v);ad[v].push_back(u);
    ab[u].push_back(w);ab[v].push_back(w);
     ed.push_back({u,v,w});
  }
  dfs(1,-1,0);bridge(1,-1);
  for(auto x:br)
  {
    //cout<<x.first<<" "<<x.second<<endl;
    mp[x]=1;mp[{x.second,x.first}]=1;
  }
  int cnt=0;
  for(int i=1;i<=n;i++)
  {
    if(com[i]==0)dfs(i,++cnt);
  }
  for(int i=1;i<=n;i++)ab[i].clear();
  for(auto x:ed)
  {
    if(com[x[0]]==com[x[1]])continue;
    //cout<<com[x[0]]<<" "<<com[x[1]]<<" "<<x[2]<<endl;
    an[com[x[0]]].push_back({com[x[1]],x[2]});
    an[com[x[1]]].push_back({com[x[0]],x[2]});
  }
  dds(1,-1,0,0);
  int a,b;cin>>a>>b;
  if(raise(com[a],com[b]))cout<<"YES\n";else cout<<"NO\n";
  return 0;
}