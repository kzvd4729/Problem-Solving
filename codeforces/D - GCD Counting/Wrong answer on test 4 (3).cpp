/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/11/2019 23:21                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 20900 KB                             
*  problem: https://codeforces.com/contest/1101/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],ans,vis[N+2];
map<int,int>ds[N+2];
map<int,vector<pair<int,int> > >dis[N+2];
vector<int>adj[N+2],fc[N+2];
void factorize(void)
{
  int mx=0;
  for(int i=2;i<=N;i++)
  {
    if(vis[i])continue;
    for(int j=i;j<=N;j+=i)
    {
      vis[j]=1;
      fc[j].push_back(i);
      mx=max(mx,(int)fc[j].size());
    }
  }
  //cout<<"*"<<mx<<endl;
}
void dfs(int node,int par)
{
  map<int,priority_queue<pair<int,int> > >pq;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);int xx=__gcd(aa[node],aa[x]);
    if(xx>1)
    {
      for(auto z:fc[xx])
      {
        pq[z].push({dis[x][z][0].first+1,x});
      }
    }
  }
   for(auto x:fc[aa[node]])
  {
    pq[x].push({1,node});
    pq[x].push({0,node});
  }
  //if(aa[node]>1)pq.push({1,node});
  //else pq.push({0,node});
  //pq.push({0,-1});
   for(auto x:fc[aa[node]])
  {
    dis[node][x].push_back(pq[x].top());
    ans=max(ans,pq[x].top().first);
    pq[x].pop();
    dis[node][x].push_back(pq[x].top());
  }
   //dis[node][0]=pq.top();pq.pop();
  //dis[node][1]=pq.top();
   //return dis[node][0].first;
}
void dds(int node,int par)
{
  for(auto x:adj[node])
  {
    if(x==par)continue;
        int xx=__gcd(aa[node],aa[x]);
    if(xx>1)
    {
      for(auto z:fc[xx])
      {
        if(x==dis[node][z][0].second)
        {
          ds[x][z]=max(ds[node][z],dis[node][z][1].first);
          ans=max(ans,ds[x][z]);
        }
      }
    }
    else
    {
      for(auto z:fc[aa[node]])
      {
        ds[node][z]=1;
      }
    }
    dds(x,node);
  }
}  
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  factorize();int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,-1);
  for(auto z:fc[aa[1]])
  {
    ds[1][z]=1;
  }
  dds(1,-1);
  cout<<ans<<endl;
  return 0;
}