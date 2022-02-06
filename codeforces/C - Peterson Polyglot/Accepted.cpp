/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/12/2019 20:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 296 ms                                          memory_used: 85000 KB                             
*  problem: https://codeforces.com/contest/778/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int sz[N+2],trie[N+N+2][26],cnt,nw;
vector<pair<int,int> >adj[N+2],clr;
vector<int>lev[N+2];
void dfs(int node,int h)
{
  lev[h].push_back(node);sz[node]=1;
  for(auto &x:adj[node])
  {
    dfs(x.first,h+1);sz[node]+=sz[x.first];
    trie[node][x.second]=x.first;
  }
}
void add(int big,int sml)
{
  for(auto &x:adj[sml])
  {
    if(!trie[big][x.second])
      trie[big][x.second]=++nw,clr.push_back({big,x.second});
    else cnt--;
    add(trie[big][x.second],x.first);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;char c;cin>>u>>v>>c;
    adj[u].push_back({v,c-'a'});
  }
  dfs(1,1);int ans=n+1,id;
  for(int h=1;h<=n;h++)
  {
    cnt=n;
    for(auto &node:lev[h])
    {
      cnt-=adj[node].size();
      int big=-1,mx=-1;
      for(auto &x:adj[node])
        if(sz[x.first]>mx)mx=sz[x.first],big=x.first;
      if(big==-1)continue;nw=n;
      for(auto &x:adj[node])
      {
        if(x.first==big)continue;
        add(big,x.first);
      }
      for(auto &x:clr)
        trie[x.first][x.second]=0;
      clr.clear();
    }
    if(cnt<ans)ans=cnt,id=h;
  }
  cout<<ans<<" "<<id<<endl;
  return 0;
}