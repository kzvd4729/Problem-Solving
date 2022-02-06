/****************************************************************************************
*  @author: kzvd4729                                         created: May/25/2020 11:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 421 ms                                          memory_used: 49400 KB                             
*  problem: https://codeforces.com/contest/1144/problem/F
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
const int N=1e6;
vector<int>adj[N+2];int cl[N+2];
map<pair<int,int>,int>mp;vector<pair<int,int> >ed;
void dfs(int node,int c)
{
  if(cl[node]!=-1&&cl[node]!=c)
    cout<<"NO\n",exit(0);
  if(cl[node]!=-1)return ;
  cl[node]=c;
  for(auto x:adj[node])
  {
    dfs(x,c^1);
    if(!c)ed.push_back({node,x});
  }
}
int ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);mp[{u,v}]=i;
    adj[v].push_back(u);
  }
  memset(cl,-1,sizeof cl);
  dfs(1,0);cout<<"YES\n";
  for(auto x:ed)
  {
    if(mp.count(x))ans[mp[x]]=0;
    else ans[mp[{x.second,x.first}]]=1;
  }
  for(int i=1;i<=m;i++)cout<<ans[i];cout<<endl;
  return 0;
}