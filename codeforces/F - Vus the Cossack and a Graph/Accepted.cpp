/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/01/2019 22:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 3322 ms                                         memory_used: 184000 KB                            
*  problem: https://codeforces.com/contest/1186/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int vis[N+2];
set<int>adj[N+2];vector<int>cn,path;
void dfs(int node)
{
  cn.push_back(node);
  vis[node]=1;
  for(auto x:adj[node])
  {
    if(vis[x])continue;
    dfs(x);
  }
}
bool eulerCircuit(int start)
{
  stack<int>st;st.push(start);
  while(!st.empty())
  {
    int u=st.top();
    if(adj[u].size()==0)
    {
      path.push_back(u);
      st.pop();
    }
    else
    {
      int v=*adj[u].begin();st.push(v);
      adj[u].erase(v);adj[v].erase(u);
    }
  }
  reverse(path.begin(),path.end());
  /*for(auto x:path)
    cout<<x<<" ";
  cout<<endl;*/
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;set<pair<int,int> >ed;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].insert(v);
    adj[v].insert(u);
    ed.insert({min(u,v),max(u,v)});
  }
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    cn.clear();dfs(i);
    if(cn.size()==1)continue;
     adj[0].clear();
    for(auto x:cn)
    {
      if(adj[x].size()%2==0)continue;
      adj[x].insert(0);
      adj[0].insert(x);
    }
    path.clear();eulerCircuit(cn[0]);
    int dl=0;int f=0;
    for(int i=0;i<path.size()-3;i++)
    {
      if(path[i]&&path[i+1]&&path[i+2]&&path[i+3])
        ed.erase({min(path[i+1],path[i+2]),max(path[i+1],path[i+2])}),i++;
    }
  }
  cout<<ed.size()<<"\n";
  for(auto x:ed)
    cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}