/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/05/2020 13:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1310 ms                                         memory_used: 70800 KB                             
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
const long N=1e6;
const long mod=1e9+7;
long big(long b,long p)
{
  long r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;
    b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
long a[N+2],sz,vis[N+2];
vector<long>adj[N+2];
void dfs(long node)
{
  if(vis[node])return ;vis[node]=1;sz++;
  for(auto x:adj[node])dfs(x);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m,k;cin>>n>>m>>k;
  for(long i=1;i<=n;i++)cin>>a[i];
   long tt=big(2,n+k);long mn=0;//cout<<tt<<endl;
  map<long,vector<pair<long,long> > >mp;
  for(long i=1;i<=m;i++)
  {
    long u,v;cin>>u>>v;
    mp[(a[u]^a[v])].push_back({u,v});
  }
  for(auto x:mp)
  {
    vector<long>v;
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
    long cnt=0;sz=0;
    for(auto x:v)
    {
      if(vis[x])continue;
      dfs(x),cnt++;
    }
    long now=(big(2,sz)-big(2,cnt)+mod)%mod;
    now=(1LL*now*big(2,n-sz))%mod;
    mn=(mn+now)%mod;
     for(auto x:v)adj[x].clear(),vis[x]=0;
  }
  cout<<(tt-mn+mod)%mod<<endl;
  return 0;
}