/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/09/2018 19:19                        
*  solution_verdict: Time limit exceeded on test 19          language: GNU C++14                               
*  run_time: 5000 ms                                         memory_used: 4100 KB                              
*  problem: https://codeforces.com/contest/342/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const int inf=1e8;
int n,m,u,v,t,x,dis[N+2];
vector<int>adj[N+2];
void upd(int node)
{
  queue<int>q;
  q.push(node);
  dis[node]=0;
  while(q.size())
  {
    node=q.front();
    q.pop();
    for(auto x:adj[node])
    {
      if(dis[node]+1<dis[x])
      {
        dis[x]=dis[node]+1;
        q.push(x);
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<n;i++)
  {
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i=1;i<=n;i++)dis[i]=inf;
  upd(1);
  while(m--)
  {
    cin>>t>>x;
    if(t==1)
      upd(x);
    else cout<<dis[x]<<endl;
  }
  return 0;
}