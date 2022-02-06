/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/02/2020 18:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 451 ms                                          memory_used: 47100 KB                             
*  problem: https://codeforces.com/contest/1363/problem/E
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
#define long long long
using namespace std;
const int N=1e6;
int a[N+2],b[N+2],c[N+2],aa[N+2],bb[N+2];
vector<int>adj[N+2];long ans=0;
void dfs(int node,int par,int cs)
{
  int f=0;if(a[node]<cs)f=1;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node,min(cs,a[node]));
    aa[node]+=aa[x],bb[node]+=bb[x];
  }
  if(b[node]==0&&c[node]==1)aa[node]++;
  if(b[node]==1&&c[node]==0)bb[node]++;
   if(f)
  {
    int mn=min(aa[node],bb[node]);
    ans+=2LL*mn*a[node];
    aa[node]-=mn,bb[node]-=mn;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  dfs(1,-1,2e9);if(aa[1]+bb[1])cout<<-1<<endl;else cout<<ans<<endl;
  return 0;
}