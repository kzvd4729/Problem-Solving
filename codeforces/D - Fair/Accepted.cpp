/****************************************************************************************
*  @author: kzvd4729                                         created: May/31/2018 00:48                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 1247 ms                                         memory_used: 48700 KB                             
*  problem: https://codeforces.com/contest/987/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e8;
const int N=1e5;
int n,m,s,k,dis[102][N+2];
vector<int>el[N+2],adj[N+2];
void bfs(int x)
{
  queue<int>q;
  for(int i=1;i<=n;i++)dis[x][i]=inf;
  for(auto xx:el[x])
  {
    dis[x][xx]=0;
    q.push(xx);
  }
  while(q.size())
  {
    int node=q.front();
    q.pop();
    for(auto xx:adj[node])
    {
      if(dis[x][xx]!=inf)continue;
      dis[x][xx]=dis[x][node]+1;
      q.push(xx);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m>>s>>k;
  for(int i=1;i<=n;i++)
  {
    int x;
    cin>>x;
    el[x].push_back(i);
  }
  for(int i=1;i<=m;i++)
  {
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i=1;i<=s;i++)
    bfs(i);
  for(int i=1;i<=n;i++)
  {
    vector<int>v;
    int ans=0;
    for(int j=1;j<=s;j++)
      v.push_back(dis[j][i]);
    sort(v.begin(),v.end());
    for(int j=0;j<k;j++)
      ans+=v[j];
    cout<<ans<<" ";
  }
  cout<<endl;
  return 0;
}