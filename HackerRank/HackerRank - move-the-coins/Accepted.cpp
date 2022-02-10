/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-09-09 12:49:05                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 754                                        memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-move-the-coins
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long 
using namespace std;
const int N=1e5;
vector<int>ad[N+2];
int c[N+2],p[N+2],dp[N+2][2],ent[N+2],ext[N+2],tim;
void dfs(int nd,int par,int l)
{
  l%=2;p[nd]=l,ent[nd]=++tim;
  for(auto x:ad[nd])
  {
    if(x==par)continue;
    dfs(x,nd,l+1);
    dp[nd][0]^=dp[x][0],dp[nd][1]^=dp[x][1];
  }
  dp[nd][l]^=c[nd];ext[nd]=tim;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>c[i];

  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    ad[u].push_back(v);ad[v].push_back(u);
  }
  dfs(1,-1,0);

  int q;cin>>q;
  while(q--)
  {
    int u,v;cin>>u>>v;
    if(ent[v]>=ent[u]&&ent[v]<=ext[u])
    {
      cout<<"INVALID\n";continue;
    }
    int xx=dp[1][1];
    if(p[u]==p[v])xx^=(dp[u][0]^dp[u][1]);
    if(xx)cout<<"YES\n";else cout<<"NO\n";
  }
  return 0;
}