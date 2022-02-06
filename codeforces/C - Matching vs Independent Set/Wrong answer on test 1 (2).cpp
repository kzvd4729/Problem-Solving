/****************************************************************************************
*  @author: kzvd4729                                         created: May/15/2020 17:32                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 50700 KB                             
*  problem: https://codeforces.com/contest/1198/problem/C
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
#define long long long
using namespace std;
const int N=2e6,inf=1e9+2;
int vs[N+2],ind[N+2],mtc[N+2];
vector<int>is,ms;
vector<pair<int,int> >adj[N+2];
void dfs(int node)
{
  vs[node]=1;
  int f=0;for(auto x:adj[node])f|=ind[x.first];
  if(!f)ind[node]=1,is.push_back(node);
  for(auto x:adj[node])
  {
    if(vs[x.first])continue;
    if(mtc[node]==0&&mtc[x.first]==0)
      ms.push_back(x.second),mtc[node]=1,mtc[x.first]=1;
    dfs(x.first);
  }
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;is.clear(),ms.clear();
    for(int i=1;i<=3*n;i++)adj[i].clear(),vs[i]=0,ind[i]=0,mtc[i]=0;
    for(int i=1;i<=m;i++)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back({v,i});
      adj[v].push_back({u,i});
    }
    vector<int>tmp;
    for(int i=2;i<=n+n+n;i++)tmp.push_back(i);
    shuffle(tmp.begin(),tmp.end(),rng);
    for(auto i:tmp)
    {
      if(vs[i])continue;dfs(i);
    }
    //assert(is.size()>=n||ms.size()>=n);
    if(is.size()>=n)
    {
      cout<<"IndSet\n";
      for(auto x:is)cout<<x<<" ";cout<<"\n";
    }
    else if(ms.size()>=n)
    {
      cout<<"Matching\n";
      for(auto x:ms)cout<<x<<" ";cout<<"\n";
    }
    else assert(0);
  }
  return 0;
}