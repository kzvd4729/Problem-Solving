/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/02/2020 00:15                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 2776 ms                                         memory_used: 170700 KB                            
*  problem: https://codeforces.com/contest/1042/problem/F
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
#define long long long 
using namespace std;
const int N=1e6;
int ent[N+2],tim;
vector<int>adj[N+2];
int lev[N+2],sp[N+2][21];
void reckon(int n,int p,int h)
{
  sp[n][0]=p;lev[n]=h;ent[n]=++tim;
  for(auto x:adj[n])
    if(x!=p)reckon(x,n,h+1);
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
int dis(int u,int v)
{
  int l=lca(u,v);
  return lev[u]+lev[v]-2*lev[l];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  int r=1;
  for(int i=1;i<=n;i++)if(adj[i].size()>1)r=i;
  reckon(r,-1,0);sparse(n);
   vector<int>v;set<pair<int,int> >st;
  for(int i=1;i<=n;i++)
  {
    if(adj[i].size()>1)continue;
    v.push_back(i);st.insert({ent[i],i});
  }
  sort(v.begin(),v.end(),[&](int a,int b){
    return lev[a]>lev[b];
  });
  st.insert({0,0});int ans=0;
  for(auto x:v)
  {
    if(st.find({ent[x],x})==st.end())continue;
    ans++;vector<int>dl;dl.push_back(x);
     auto it=st.lower_bound({ent[x]+1,-1});
    while(it!=st.end())
    {
      if(dis(x,it->second)<=k)dl.push_back(it->second);
      else break;
       it++;
    }
     it=st.lower_bound({ent[x],-1});it--;
    while(it!=st.begin())
    {
      if(dis(x,it->second)<=k)dl.push_back(it->second);
      else break;
       it--;
    }
    for(auto d:dl)st.erase({ent[d],d});
  }
  cout<<ans<<endl;
  return 0;
}