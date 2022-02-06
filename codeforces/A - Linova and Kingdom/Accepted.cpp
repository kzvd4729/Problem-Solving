/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/16/2020 12:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 218 ms                                          memory_used: 47500 KB                             
*  problem: https://codeforces.com/contest/1336/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int sub[N+2],ch[N+2],prnt[N+2],ds[N+2];
vector<int>adj[N+2];
priority_queue<pair<int,int> >pq;
void dfs(int node,int par,int d)
{
  sub[node]=1,prnt[node]=par,ds[node]=d;
  for(auto x:adj[node])
  {
    if(x==par)continue;ch[node]++;
    dfs(x,node,d+1);sub[node]+=sub[x];
  }
  if(ch[node]==0)pq.push({d,node});
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,0,0);long ans=0;
  while(k--)
  {
    pair<int,int>p=pq.top();pq.pop();ans+=p.first;
    int nd=p.second;int pr=prnt[nd];
    ch[pr]--;
    if(ch[pr]==0)pq.push({-(sub[pr]-1)+ds[pr],pr});
  }
  cout<<ans<<endl;
  return 0;
}