/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/15/2018 21:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 233 ms                                          memory_used: 23600 KB                             
*  problem: https://codeforces.com/contest/1093/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long mod=998244353;
int col[N+2],f,cnt[2];
vector<int>adj[N+2];
long bigmod(long b,long p,long mod)
{
  long ret=1LL;
  while(p)
  {
    if(p%2)ret=(ret*b)%mod;
    b=(b*b)%mod;p/=2;
  }
  return ret;
}
void dfs(int node,int cl)
{
  if(col[node]==-1)
  {
    cnt[cl]++;
    col[node]=cl;
  }
  else
  {
    if(col[node]!=cl)f=1;
    return ;
  }
  for(auto x:adj[node])
    dfs(x,cl^1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
      adj[i].clear();col[i]=-1;
    }
    while(m--)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    long ans=1;f=0;
    for(int i=1;i<=n;i++)
    {
      cnt[0]=0;cnt[1]=0;
      if(col[i]==-1)
      {
        dfs(i,0);
        long xx=bigmod(2,cnt[0],mod)%mod;
        xx=(xx+bigmod(2,cnt[1],mod)%mod)%mod;
        ans=(ans*xx)%mod;
        //cout<<ans<<endl;
      }
    }
    if(f)ans=0;
    cout<<ans<<"\n";
  }
  return 0;
}