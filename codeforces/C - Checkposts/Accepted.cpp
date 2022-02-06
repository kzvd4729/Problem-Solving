/****************************************************************************************
*  @author: kzvd4729                                         created: May/30/2018 16:00                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 421 ms                                          memory_used: 10600 KB                             
*  problem: https://codeforces.com/contest/427/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const long mod=1e9+7;
int n,m,nodes[N+2],stacked[N+2];
int low[N+2],desc[N+2],tim;
long ans=1,cost;
vector<int>adj[N+2];
stack<int>st;
void dfs(int node)
{
  desc[node]=low[node]=++tim;
  st.push(node);
  stacked[node]=1;
  for(auto x:adj[node])
  {
    if(desc[x]==0)
    {
      dfs(x);
      low[node]=min(low[node],low[x]);
    }
    else if(stacked[x])
      low[node]=min(low[node],low[x]);
  }
  if(low[node]==desc[node])
  {
    int mncost=2e9,cnt=0,now=-1;
    while(now!=node)
    {
      now=st.top();
      st.pop();
      stacked[now]=0;
      if(nodes[now]==mncost)cnt++;
      if(nodes[now]<mncost)
        mncost=nodes[now],cnt=1;
    }
    ans=(ans*(cnt*1LL))%mod;
    cost+=(mncost*1LL);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>nodes[i];
  cin>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
  }
  for(int i=1;i<=n;i++)
  {
    if(desc[i])continue;
    dfs(i);
  }
//  for(int i=1;i<=n;i++)
//    cout<<i<<" "<<desc[i]<<" "<<low[i]<<endl;
  cout<<cost<<" "<<ans<<endl;
  return 0;
}