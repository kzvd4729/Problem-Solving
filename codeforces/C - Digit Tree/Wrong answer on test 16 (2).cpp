/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/21/2018 03:35                        
*  solution_verdict: Wrong answer on test 16                 language: GNU C++14                               
*  run_time: 842 ms                                          memory_used: 8600 KB                              
*  problem: https://codeforces.com/contest/715/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long n,tot,sz[N+2],mark[N+2];
long mod,ph,ten[N+2],ans;
vector<pair<long,long> >adj[N+2];
map<long,long>mp;
void phi(long x)
{
  ph=x;
  for(long i=2;i<=N;i++)
  {
    if(x%i)continue;ph/=x;ph*=(x-1);
    while(x%i==0)x/=i;
  }
  if(x!=1)
  {
    ph/=x;ph*=(x-1);
  }
}
long bigmod(long b,long p,long mod)
{
  long ret=1LL;
  while(p)
  {
    if(p&1)ret=(ret*b)%mod;
    b=(b*b)%mod;p/=2;
  }
  return ret;
}
void dfs(long node,long par)
{
  tot++;sz[node]=1;
  for(auto x:adj[node])
  {
    if(mark[x.first]||x.first==par)continue;
    dfs(x.first,node);sz[node]+=sz[x.first];
  }
}
long find_center(long node,long par)
{
  for(auto x:adj[node])
  {
    if(mark[x.first]||x.first==par)continue;
    if(sz[x.first]>tot/2)return find_center(x.first,node);
  }
  return node;
}
void add_all(long node,long par,long now,long dg)
{
  now%=mod;
  if(par!=-1)
  {
    mp[now]++;if(!now)ans++;
  }
  for(auto x:adj[node])
  {
    if(mark[x.first]||x.first==par)continue;
    add_all(x.first,node,(x.second*1LL*ten[dg]+now)%mod,dg+1);
  }
}
void upd(long node,long par,long now,long dg,long vl)
{
  now%=mod;mp[now]+=vl;
  for(auto x:adj[node])
  {
    if(mark[x.first]||x.first==par)continue;
    upd(x.first,node,(x.second*1LL*ten[dg]+now)%mod,dg+1,vl);
  }
}
void cal(long node,long par,long now,long dg)
{
  now%=mod;if(!now)ans++;
  long inv=bigmod(ten[dg],ph-1,mod);
  long tmp=(inv*now)%mod;tmp=(mod-tmp)%mod;
  ans+=mp[tmp];
  for(auto x:adj[node])
  {
    if(mark[x.first]||x.first==par)continue;
    cal(x.first,node,(now*10LL+x.second*1LL)%mod,dg+1);
  }
}
void centroid(long node,long par)
{
  tot=0;dfs(node,-1);
  long center=find_center(node,-1);
  mark[center]=1;
  add_all(center,-1,0,0);
  for(auto x:adj[center])
  {
    if(mark[x.first])continue;
    upd(x.first,-1,x.second,1,-1);
    cal(x.first,-1,x.second,1);
    upd(x.first,-1,x.second,1,+1);
  }
  mp.clear();
  for(auto x:adj[center])
  {
    if(mark[x.first])continue;
    centroid(x.first,center);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>mod;phi(mod);ten[0]=1;
  for(long i=1;i<=n;i++)ten[i]=(ten[i-1]*10LL)%mod;
  for(long i=1;i<n;i++)
  {
    long u,v,w;cin>>u>>v>>w;u++,v++;
    adj[u].push_back({v,w});adj[v].push_back({u,w});
  }
  centroid(1,-1);cout<<ans<<endl;
  return 0;
}