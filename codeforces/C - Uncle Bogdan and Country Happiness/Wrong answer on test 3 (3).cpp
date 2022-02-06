/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/01/2020 11:39                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 9100 KB                              
*  problem: https://codeforces.com/contest/1388/problem/C
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=2e5;
int a[N+2],b[N+2],f,gd[N+2],bd[N+2];
vector<int>adj[N+2];
void dfs(int node,int par)
{
  for(auto x:adj[node])
    if(x!=par)dfs(x,node),gd[node]+=gd[x],bd[node]+=bd[x];
  bd[node]+=a[node];
   if(b[node]<gd[node]-bd[node]){f=1;return;}
  int rm=b[node]-(gd[node]-bd[node]);
  if(rm%2){f=1;return;}
    gd[node]+=rm/2;bd[node]-=rm/2;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++)adj[i].clear(),gd[i]=0,bd[i]=0;
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    f=0;dfs(1,-1);if(f)cout<<"NO\n";
    else cout<<"YES\n";
  }
  return 0;
}