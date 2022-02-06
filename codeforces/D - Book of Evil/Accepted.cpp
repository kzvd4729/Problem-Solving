/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/14/2018 01:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 11800 KB                             
*  problem: https://codeforces.com/contest/337/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const int inf=1e8;
int n,m,d,u,v,x,evil[N+2];
int dp[N+2],ans;
vector<int>adj[N+2];
int dfs(int node,int par)
{
  if(evil[node])dp[node]=0;
  else dp[node]=-inf;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dp[node]=max(dp[node],dfs(x,node)+1);
  }
  return dp[node];
}
void dds(int node,int par,int ln)
{
  if(evil[node])ln=max(ln,0);
  //if(node==3)cout<<ln<<endl;
  if(max(ln,dp[node])<=d)ans++;
  set<pair<int,int> >st;
  st.insert({-(ln+1),par});
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(dp[x]<=N)st.insert({-(dp[x]+2),x});
  }
  for(auto x:adj[node])
  {
    if(x==par)continue;
    st.erase({-(dp[x]+2),x});
    pair<int,int>p=*st.begin();
    dds(x,node,-p.first);
    st.insert({-(dp[x]+2),x});
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m>>d;
  for(int i=1;i<=m;i++)
  {
    cin>>x;
    evil[x]=1;
  }
  for(int i=1;i<n;i++)
  {
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,-1);
//  for(int i=1;i<=n;i++)
//    cout<<dp[i]<<" ";
//  cout<<endl;
  dds(1,-1,-inf);
  cout<<ans<<endl;
  return 0;
}