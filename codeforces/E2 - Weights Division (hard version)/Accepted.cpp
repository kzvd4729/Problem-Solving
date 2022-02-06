/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/16/2020 10:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1262 ms                                         memory_used: 171200 KB                            
*  problem: https://codeforces.com/contest/1399/problem/E2
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
const int N=4e6;
vector<int>adj[N+2];
int sz[N+2],lv[N+2];
void dfs(int node,int par,int h)
{
  lv[node]=h;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node,h+1);sz[node]+=sz[x];
  }
  if(adj[node].size()==1&&par!=-1)sz[node]=1;
}
int cs[N+2];long one[N+2],two[N+2];
void solve()
{
  int n;long s;cin>>n>>s;
  for(int i=1;i<=n;i++)adj[i].clear(),sz[i]=0;
  vector<vector<int> >a,b;
  for(int i=1;i<n;i++)
  {
    int u,v,w,ty;cin>>u>>v>>w>>ty;
    if(ty==1)a.push_back({u,v,w});
    else b.push_back({u,v,w});
    adj[u].push_back(v);adj[v].push_back(u);
  }
  dfs(1,-1,0);long sm=0;
   priority_queue<pair<long,int> >pq;pq.push({0,0});
  for(auto x:a)
  {
    int u=x[0],v=x[1];if(lv[u]>lv[v])swap(u,v);
    sm+=1LL*sz[v]*x[2];pq.push({1LL*sz[v]*(x[2]-x[2]/2),v});
    cs[v]=x[2];
  }
  long ad=0;
  for(int i=1;i<=40*n;i++)
  {
    pair<long,int>p=pq.top();pq.pop();
    ad+=p.first;int v=p.second;cs[v]/=2;
    pq.push({1LL*sz[v]*(cs[v]-cs[v]/2),v});
    one[i]=ad;
  }
   while(pq.size())pq.pop();pq.push({0,0});
  for(auto x:b)
  {
    int u=x[0],v=x[1];if(lv[u]>lv[v])swap(u,v);
    sm+=1LL*sz[v]*x[2];pq.push({1LL*sz[v]*(x[2]-x[2]/2),v});
    cs[v]=x[2];
  }
  ad=0;
  for(int i=1;i<=40*n;i++)
  {
    pair<long,int>p=pq.top();pq.pop();
    ad+=p.first;int v=p.second;cs[v]/=2;
    pq.push({1LL*sz[v]*(cs[v]-cs[v]/2),v});
    two[i]=ad;
  }
  long df=sm-s;int ans=1e9;
  for(int i=0;i<=40*n;i++)
  {
    int id=lower_bound(two,two+40*n+1,df-one[i])-two;
    ans=min(ans,i+id*2);
  }
  cout<<ans<<"\n";
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}