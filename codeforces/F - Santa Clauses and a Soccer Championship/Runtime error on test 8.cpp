/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/03/2019 19:10                        
*  solution_verdict: Runtime error on test 8                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 31500 KB                             
*  problem: https://codeforces.com/contest/752/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int n,k,sz[N+2],tem[N+2];
vector<int>adj[N+2];
void dfs1(int node,int par)
{
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs1(x,node);sz[node]+=sz[x];
  }
}
int dfs2(int node,int par)
{
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(sz[x]>k)return dfs2(x,node);
  }
  return node;
}
vector<int>v[N+2];
void dfs3(int node,int par,int id)
{
  if(tem[node])v[id].push_back(node);
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs3(x,node,id);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  for(int i=1;i<=k+k;i++)
  {
    int x;cin>>x;sz[x]=1;tem[x]=1;
  }
  dfs1(1,-1);int center=dfs2(1,-1);
  cout<<1<<"\n"<<center<<"\n";
   int cnt=0;
  for(auto x:adj[center])dfs3(x,center,++cnt);
   //cout<<"*"<<cnt<<endl;
  // for(int i=1;i<=cnt;i++)
  //   cout<<"*"<<v[i].size()<<endl;
   priority_queue<pair<int,int> >pq;
  for(int i=1;i<=cnt;i++)if(v[i].size())pq.push({v[cnt].size(),i});
   while(pq.size()>=2)
  {
    int p1=pq.top().second;pq.pop();
    int p2=pq.top().second;pq.pop();
     cout<<v[p1].back()<<" "<<v[p2].back()<<" "<<center<<"\n";
    v[p1].pop_back();v[p2].pop_back();
     if(v[p1].size())pq.push({v[p1].size(),p1});
    if(v[p2].size())pq.push({v[p2].size(),p2});
  }
  if(pq.size())
  {
    if(v[pq.top().second].size()>1)assert(0);
    cout<<center<<" "<<v[pq.top().second].back()<<" "<<center<<"\n";
  }
    return 0;
}