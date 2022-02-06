/****************************************************************************************
*  @author: * kzvd4729                                       created: Aug/20/2019 21:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 342 ms                                          memory_used: 10300 KB                             
*  problem: https://codeforces.com/contest/1204/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
int dis[N+2][N+2];
vector<int>adj[N+2];
void bfs(int nd)
{
  for(int i=1;i<=100;i++)
    dis[nd][i]=1e9;
  dis[nd][nd]=0;
  queue<int>q;q.push(nd);
  while(q.size())
  {
    int u=q.front();q.pop();
    for(auto v:adj[u])
    {
      if(dis[nd][v]>dis[nd][u]+1)
      {
        dis[nd][v]=dis[nd][u]+1;
        q.push(v);
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    for(int j=1;j<=n;j++)
      if(s[j-1]=='1')adj[i].push_back(j);
  }
  for(int i=1;i<=n;i++)bfs(i);
   int m;cin>>m;vector<int>aa(m+1),ans;
  for(int i=1;i<=m;i++)cin>>aa[i];
   ans.push_back(aa[1]);int id=2;
  while(id<=m)
  {
    int mx=id;
    for(int i=id;i<=min(m,id+120);i++)
    {
      if(dis[ans.back()][aa[i]]==i-id+1)
        mx=i;
    }
    id=mx;
    ans.push_back(aa[id]);id++;
  }
  cout<<ans.size()<<endl;
  for(auto x:ans)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}