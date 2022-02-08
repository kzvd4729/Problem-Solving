/****************************************************************************************
*  @author: kzvd4729                                         created: 15-12-2018 12:39:49                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.02 sec                                        memory_used: 117.9M                               
*  problem: https://www.codechef.com/DEC18A/problems/DLDAG
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define endl "\n"
using namespace std;
const int N=1e6;
int in[N+2],vis[N+2],cnt,pnt[N+2];
vector<vector<int> >ans;set<int>ed[N+2];
vector<int>adj[N+2],pth[N+2];
int dfs(int node)
{
  vis[node]=1;vector<int>v;
  for(auto x:adj[node])
  {
    if(vis[x])continue;
    v.push_back(dfs(x));
  }
  set<pair<int,int> >st;
  for(auto x:v)
    st.insert({pth[x].size(),x});
  while(st.size())
  {
    if(st.size()==1)break;
    pair<int,int>p1=*st.rbegin();st.erase(p1);
    pair<int,int>p2=*st.rbegin();st.erase(p2);
    int a=pth[p1.second][pnt[p1.second]++];
    int b=pth[p2.second][pnt[p2.second]++];
    if(ed[a].find(b)==ed[a].end())
      ans.push_back({2,a,b});
    else
    {
      ans.push_back({1,a});ans.push_back({1,b});
    }
    p1.first--;p2.first--;
    if(p1.first)st.insert(p1);if(p2.first)st.insert(p2);
  }
  int id;
  if(st.size())
    id=st.begin()->second;
  else id=++cnt;
  pth[id].push_back(node);
  return id;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  while(m--)
  {
    int u,v;cin>>u>>v;in[v]++;
    adj[u].push_back(v);
    ed[u].insert(v);ed[v].insert(u);
  }
  for(int i=1;i<=n;i++)
    if(!in[i])adj[0].push_back(i);
  int id=dfs(0);
  for(int i=pnt[id];i<pth[id].size()-1;i++)
    ans.push_back({1,pth[id][i]});
  cout<<ans.size()<<endl;
  for(auto xx:ans)
  {
    for(auto x:xx)
    {
      cout<<x<<" ";
    }
    cout<<endl;
  }
  return 0;
}