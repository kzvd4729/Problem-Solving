/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/07/2020 00:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 18200 KB                             
*  problem: https://codeforces.com/contest/1404/problem/B
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
vector<int>adj[N+2];
int mx,rt,n,ds[N+2];
void dfs(int nd,int par,int ds)
{
  if(ds>mx)mx=ds,rt=nd;
  for(auto x:adj[nd])
    if(x!=par)dfs(x,nd,ds+1);
}
void bfs(int nd)
{
  for(int i=1;i<=n;i++)ds[i]=1e9;
   queue<int>q;q.push(nd);ds[nd]=0;
  while((int)q.size())
  {
    int u=q.front();q.pop();
    for(auto x:adj[u])
      if(ds[u]+1<ds[x])ds[x]=ds[u]+1,q.push(x);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int a,b,da,db;cin>>n>>a>>b>>da>>db;
    for(int i=1;i<=n;i++)adj[i].clear();
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);adj[v].push_back(u);
    }
    mx=0;dfs(1,-1,0);mx=0;dfs(rt,-1,0);
    da=min(da,mx),db=min(db,mx);bfs(a);
    if(ds[b]<=da)cout<<"Alice\n";
    else if(db>da*2)cout<<"Bob\n";
    else cout<<"Alice\n";
  }
  return 0;
}