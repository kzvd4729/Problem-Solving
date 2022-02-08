/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-14 20:12:48                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 178 ms                                          memory_used: 67576 KB                             
*  problem: https://atcoder.jp/contests/agc035/tasks/agc035_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int deg[N+2],bln[N+2];
set<int>adj[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].insert(v);deg[u]++;
    adj[v].insert(u);deg[v]++;
  }
  set<pair<int,int> >st;
  for(int i=1;i<=n;i++)
    st.insert({deg[i],i});
  vector<pair<int,int> >ed;
  while(st.size())
  {
    pair<int,int>p=*st.begin();
    int u=p.second,v;
    if(bln[u])
    {
      v=*adj[u].begin();
      ed.push_back({u,v});bln[u]^=1;
      adj[u].erase(v);adj[v].erase(u);
      st.erase({deg[u],u});
      st.erase({deg[v],v});
      deg[u]--;deg[v]--;
      if(deg[u])st.insert({deg[u],u});
      if(deg[v])st.insert({deg[v],v});
    }
    else
    {
      v=*adj[u].begin();
      ed.push_back({v,u});bln[v]^=1;
      adj[u].erase(v);adj[v].erase(u);
      st.erase({deg[u],u});
      st.erase({deg[v],v});
      deg[u]--;deg[v]--;
      if(deg[u])st.insert({deg[u],u});
      if(deg[v])st.insert({deg[v],v});
    }
  }
  for(int i=1;i<=n;i++)
    if(bln[i])cout<<-1<<endl,exit(0);
  for(auto x:ed)
    cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}