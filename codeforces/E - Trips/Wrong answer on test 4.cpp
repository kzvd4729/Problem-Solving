/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/21/2020 11:48                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 8300 KB                              
*  problem: https://codeforces.com/contest/1037/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int vis[N+2];
vector<int>com[N+2];
map<int,int>mp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
  if(k>635)
  {
    for(int i=1;i<=m;i++)cout<<0<<"\n";
    exit(0);
  }
  for(int i=1;i<=n;i++)com[i].push_back(i);
  int ans=0;k++;
  while(m--)
  {
    int u,v;cin>>u>>v;mp[u][v]=1,mp[v][u]=1;
    if(vis[u]&&vis[v]);
    else
    {
      int cnt=0;
      for(auto x:com[u])cnt+=mp[v].count(x);
      if(cnt>=k||cnt==com[u].size())
      {
        com[u].push_back(v);
        if(com[u].size()>k)ans+=(vis[v]^1),vis[v]=1;
        else if(com[u].size()==k)
        {
          for(auto x:com[u])ans+=(vis[x]^1),vis[x]=1;
        }
      }
       cnt=0;swap(u,v);
      for(auto x:com[u])cnt+=mp[v].count(x);
      if(cnt>=k||cnt==com[u].size())
      {
        com[u].push_back(v);
        if(com[u].size()>k)ans+=(vis[v]^1),vis[v]=1;
        else if(com[u].size()==k)
        {
          for(auto x:com[u])ans+=(vis[x]^1),vis[x]=1;
        }
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}