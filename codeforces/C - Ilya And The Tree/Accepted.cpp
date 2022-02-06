/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/15/2019 18:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 499 ms                                          memory_used: 36700 KB                             
*  problem: https://codeforces.com/contest/842/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],fr[N+2],ans[N+2],cnt;
vector<int>dd[N+2],adj[N+2];
void divisors(int n)
{
  int mx=0;
  for(int i=2;i<=n;i++)
  {
    for(int j=i;j<=n;j+=i)
    {
      dd[j].push_back(i);
    }
  }
}
void dfs(int node,int par,int pr)
{
  cnt++;ans[node]=pr;int now=1;
  for(auto x:dd[aa[node]])
  {
    fr[x]++;
    if(fr[x]==cnt)now=max(now,x);
    if(fr[x]>=cnt-1)ans[node]=max(ans[node],x);
  }
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node,now);
  }
  for(auto x:dd[aa[node]])
    fr[x]--;
  cnt--;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  divisors(N);int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  dfs(1,-1,1);
  for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}