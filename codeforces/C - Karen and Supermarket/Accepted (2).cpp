/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/28/2019 19:34                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 389 ms                                          memory_used: 393100 KB                            
*  problem: https://codeforces.com/contest/815/problem/C
****************************************************************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;
 const int N = 5005;
 int C[N], D[N], dp[N][N][2], n, sz[N];
 vector <int> adj[N];
 bool cmp(int a,int b)
{
  return sz[a]>sz[b];
}
void dfs(int u) 
{
  dp[u][1][1] = C[u] - D[u];
  dp[u][1][0] = C[u];
  dp[u][0][0] = 0;
  sz[u] = 1;
  if(!adj[u].size()) return;
  int mx = adj[u][0];
  for(int v: adj[u]) 
  {
    dfs(v);
    sz[u]+=sz[v];
  }
  sort(adj[u].begin(),adj[u].end(),cmp);
  int f=0;
  for(int v: adj[u]) 
  {
    if(f==0) 
    {
      for(int i = sz[v] + 1; i >= 1; i--) 
      {
        dp[u][i][1] = min(dp[v][i - 1][1], dp[v][i - 1][0]) + dp[u][1][1];
        dp[u][i][0] = min(dp[v][i][0], dp[v][i - 1][0] + dp[u][1][0]);
      }
      f=1;
    }
    else 
    {
      for(int i = sz[u]; i >= 0; i--) 
      {
        for(int j = 0; j <= min(i, sz[v]); j++) 
        {
          dp[u][i][1] = min(dp[u][i][1], dp[u][i - j][1] + dp[v][j][1]);
          dp[u][i][1] = min(dp[u][i][1], dp[u][i - j][1] + dp[v][j][0]);
          dp[u][i][0] = min(dp[u][i][0], dp[u][i - j][0] + dp[v][j][0]);
        }
      }
    }
  }
}
 int32_t main() 
{
  ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
  memset(dp, 0x3f, sizeof dp);
  int k; cin >> n >> k;
  for(int i = 1; i <= n; i++) 
  {
    int x; cin >> C[i] >> D[i];
    if(i > 1) 
    {
      cin >> x;
      adj[x].push_back(i);
    }
  }
  dfs(1);
  int ans = 0;
  for(int i = 1; i <= n; i++) 
  {
    ans += (min(dp[1][i][1], dp[1][i][0]) <= k);
  }
  cout << ans << endl;
}