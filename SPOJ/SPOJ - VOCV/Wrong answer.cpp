/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-07-31 15:37:37                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-VOCV
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e9;
const int mod=10007;
const int N=100010;
int t,n,way[N+2][2],dp[N+2][3];
vector<int>adj[N+2];
int dfs(int node,int par,int f)
{
  if(dp[node][f]!=-1)return dp[node][f];
  int here=0;
  way[node][f]=1;
  for(auto xx:adj[node])
  {
    if(xx==par)continue;
    if(f)
    {
      int tmp1=dfs(xx,node,0);
      int tmp2=1+dfs(xx,node,1);

      if(tmp1==tmp2)
        way[node][f]=(way[node][f]*(way[xx][0]+way[xx][1]))%mod;
      else if(tmp1<tmp2)
        way[node][f]=(way[node][f]*way[xx][0])%mod;
      else
        way[node][f]=(way[node][f]*way[xx][1])%mod;
      here=min(tmp1,tmp2);
    }
    else
    {
      here+=1+dfs(xx,node,1);
      way[node][f]=(way[node][f]*way[xx][1])%mod;
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
    for(int i=2;i<=n;i++)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    memset(dp,-1,sizeof(dp));
    int tmp1=dfs(1,-1,0);
    int tmp2=1+dfs(1,-1,1);

    int ans=1;

    if(tmp1==tmp2)
      ans=(way[1][0]+way[1][1])%mod;
    else if(tmp1<tmp2)
      ans=way[1][0];
    else
      ans=way[1][1];

    cout<<min(tmp1,tmp2)<<" "<<ans<<endl;
  }
  return 0;
}