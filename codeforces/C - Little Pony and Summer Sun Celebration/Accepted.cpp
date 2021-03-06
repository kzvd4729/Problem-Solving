/****************************************************************************************
*  @author: kzvd4729                                         created: May/07/2020 19:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 42000 KB                             
*  problem: https://codeforces.com/contest/453/problem/C
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
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
vector<int>adj[N+2],tre[N+2];
int cnt=0,vs[N+2],aa[N+2];
void dfs(int node)
{
  cnt+=aa[node];vs[node]=1;
  for(auto x:adj[node])
  {
    if(vs[x])continue;
    dfs(x);tre[node].push_back(x);
  }
}
bool ok[N+2],pr[N+2];
void rgr(int node)
{
  for(auto x:tre[node])
  {
    rgr(x);ok[node]|=ok[x];
  }
  ok[node]|=aa[node];
}
vector<int>ans;
void dgh(int node)
{
  for(auto x:tre[node])
  {
    if(!ok[x])continue;
    ans.push_back(node);pr[node]^=1;
    dgh(x);
  }
  ans.push_back(node);pr[node]^=1;
  for(auto x:tre[node])
  {
    if(!ok[x])continue;
    if(pr[x]==aa[x])continue;
    ans.push_back(x);ans.push_back(node);
    pr[node]^=1;pr[x]^=1;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  for(int i=1;i<=n;i++)cin>>aa[i];
  int f=0,rt=1;
  for(int i=1;i<=n;i++)
  {
    if(vs[i])continue;
    cnt=0;dfs(i);if(cnt)f++,rt=i;
  }
  if(f==0)cout<<0<<endl,exit(0);if(f>1)cout<<-1<<endl,exit(0);
  rgr(rt);dgh(rt);if(pr[rt]!=aa[rt])ans.pop_back();
  cout<<ans.size()<<"\n";
  for(auto x:ans)cout<<x<<" ";cout<<"\n";
  return 0;
}