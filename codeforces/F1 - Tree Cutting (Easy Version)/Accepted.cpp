/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/19/2019 21:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 358 ms                                          memory_used: 34200 KB                             
*  problem: https://codeforces.com/contest/1118/problem/F1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int cl[N+2],fr[N+2],sub[N+2][4],ans;
vector<int>adj[N+2];
void dfs(int node,int par)
{
  sub[node][cl[node]]=1;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);
    sub[node][1]+=sub[x][1];
    sub[node][2]+=sub[x][2];
  }
  if(sub[node][1]==0&&sub[node][2]==fr[2])
    ans++;
  else if(sub[node][2]==0&&sub[node][1]==fr[1])
    ans++;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>cl[i];fr[cl[i]]++;
  }
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,-1);cout<<ans<<endl;
  return 0;
}