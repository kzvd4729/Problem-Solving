/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/21/2019 21:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 22000 KB                             
*  problem: https://codeforces.com/contest/1139/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long mod=1e9+7;
int vis[N+2],cnt;
vector<pair<int,int> >adj[N+2];
long Bigmod(long b,long p,long mod)
{
  long ret=1LL;
  while(p)
  {
    if(p%2)ret=(ret*b)%mod;
    b=(b*b)%mod;p/=2;
  }
  return ret;
}
void dfs(int node,int par)
{
  cnt++;vis[node]=1;
  for(auto x:adj[node])
  {
    if(x.first==par)continue;
    if(!x.second)dfs(x.first,node);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<n;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  long ans=Bigmod(n,k,mod);
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    cnt=0;dfs(i,-1);
    ans=(ans-Bigmod(cnt,k,mod)+mod)%mod;
  }
  cout<<(ans+mod)%mod<<endl;
  return 0;
}