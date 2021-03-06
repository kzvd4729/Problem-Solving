/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/11/2018 00:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 732 ms                                          memory_used: 93400 KB                             
*  problem: https://codeforces.com/contest/1084/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long n,ww[N+2],dp[N+2],ans;
vector<pair<long,long> >adj[N+2];
long dfs(long node,long par)
{
  dp[node]=ww[node];
  for(auto x:adj[node])
  {
    if(x.first==par)continue;
    dp[node]=max(dp[node],ww[node]+dfs(x.first,node)-x.second);
  }
  ans=max(ans,dp[node]);
  return dp[node];
}
long dds(long node,long par,long mm)
{
  set<pair<long,long> >st;ans=max(ans,mm);
  for(auto x:adj[node])
  {
    if(x.first==par)continue;
    st.insert({dp[x.first]-x.second,x.first});
  }
  for(auto x:adj[node])
  {
    if(x.first==par)continue;
    st.erase({dp[x.first]-x.second,x.first});
    long cll=max(ww[x.first],ww[x.first]+mm-x.second);
    if(st.size())
    {
      pair<long,long>p=*st.rbegin();
      cll=max(cll,ww[x.first]+p.first+ww[node]-x.second);
    }
    dds(x.first,node,cll);
    st.insert({dp[x.first]-x.second,x.first});
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;for(long i=1;i<=n;i++)cin>>ww[i];
  for(long i=1;i<n;i++)
  {
    long u,v,c;cin>>u>>v>>c;
    adj[u].push_back({v,c});
    adj[v].push_back({u,c});
  }
  dfs(1,-1);dds(1,-1,ww[1]);
  cout<<ans<<endl;
  return 0;
}