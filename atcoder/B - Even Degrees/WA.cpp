/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-14 19:33:57                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 103 ms                                          memory_used: 57452 KB                             
*  problem: https://atcoder.jp/contests/agc035/tasks/agc035_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
set<int>adj[N+2];
vector<int>path;
bool eulerCircuit(int n,int start)
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
      int bg=*adj[u].begin();
      st.push(bg);
      adj[u].erase(bg);
      adj[bg].erase(u);
    }
  }
  reverse(path.begin(),path.end());
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,f=0;cin>>n>>m;f=m%2;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  for(int i=1;i<=n;i++)
    if(adj[i].size()%2==1)f=1;
  if(f)cout<<"-1"<<endl,exit(0);
  eulerCircuit(n,1);
  for(int i=0;i<path.size()-1;i++)
  {
    if(i%2==0)cout<<path[i]<<" "<<path[i+1]<<"\n";
    else cout<<path[i+1]<<" "<<path[i]<<"\n";
  }
  return 0;
}