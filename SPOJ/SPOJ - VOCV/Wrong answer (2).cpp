/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-07-31 01:20:26                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-VOCV
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=100010;
const int mod=10007;
int t,n,dp[N+2][2],way[N+2][2];
vector<int>adj[N+2];
int dfs(int node,int par,int f)
{
  if(dp[node][f]!=-1)return dp[node][f];
  int here=0;way[node][f]=1;
  for(auto xx:adj[node])
  {
    if(xx==par)continue;

    if(f==0)
    {
      here+=1+dfs(xx,node,1);
      way[node][f]=(way[node][f]*way[xx][1])%mod;
    }
    else
    {
      int tmp1=dfs(xx,node,0);
      int tmp2=1+dfs(xx,node,1);

      if(tmp1==tmp2)
      {
        here=tmp1;
        way[node][f]=(way[node][f]*(way[xx][1]+way[xx][0]))%mod;
      }
      else if(tmp1<tmp2)
      {
        here=tmp1;
        way[node][f]=(way[node][f]*way[xx][0])%mod;
      }
      else
      {
        here=tmp2;
        way[node][f]=(way[node][f]*way[xx][1])%mod;
      }
    }
  }
  return dp[node][f]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=1;i<=n;i++)adj[i].clear();
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    memset(dp,-1,sizeof(dp));

    int tmp1=dfs(1,-1,0);
    int tmp2=1+dfs(1,-1,1);


    if(tmp1==tmp2)
      cout<<tmp1<<" "<<(way[1][0]+way[1][1])%mod<<endl;
    else if(tmp1<tmp2)
      cout<<tmp1<<" "<<way[1][0]<<endl;
    else
      cout<<tmp2<<" "<<way[1][1]<<endl;
  }
  return 0;
}