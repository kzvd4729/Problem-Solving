/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/05/2020 13:03                        
*  solution_verdict: Runtime error on test 8                 language: GNU C++14                               
*  run_time: 1200 ms                                         memory_used: 57900 KB                             
*  problem: https://codeforces.com/contest/1039/problem/C
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
const int N=1e6;
const int mod=1e9+7;
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;
    b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
int a[N+2],sz,vis[N+2];
vector<int>adj[N+2];
void dfs(int node)
{
  if(vis[node])return ;vis[node]=1;sz++;
  for(auto x:adj[node])dfs(x);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=n;i++)cin>>a[i];
   long tt=big(2,n+k);long mn=0;//cout<<tt<<endl;
  map<long,vector<pair<int,int> > >mp;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    mp[(a[u]^a[v])].push_back({u,v});
  }
  for(auto x:mp)
  {
    vector<int>v;
    for(auto p:x.second)
    {
      v.push_back(p.first);v.push_back(p.second);
      adj[p.first].push_back(p.second);
      adj[p.second].push_back(p.first);
      //cout<<p.first<<" "<<p.second<<endl;
    }
    //cout<<endl<<endl;
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int cnt=0;sz=0;
    for(auto x:v)
    {
      if(vis[x])continue;
      dfs(x),cnt++;
    }
    int now=(big(2,sz)-big(2,cnt)+mod)%mod;
    now=(1LL*now*big(2,n-sz))%mod;
    mn=(mn+now)%mod;
     for(auto x:v)adj[x].clear(),vis[x]=0;
  }
  cout<<(tt-mn+mod)%mod<<endl;
  return 0;
}