/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/24/2020 19:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 2277 ms                                         memory_used: 97600 KB                             
*  problem: https://codeforces.com/contest/650/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,m,mx;
void compress(vector<vector<int> >&v)
{
  vector<int>u;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
      u.push_back(v[i][j]);
  }
  sort(u.begin(),u.end());
  u.erase(unique(u.begin(),u.end()),u.end());
   map<int,int>mp;
  for(int i=0;i<u.size();i++)
    mp[u[i]]=i+1;
  mx=u.size();
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
      v[i][j]=mp[v[i][j]];
  }
}
vector<pair<int,int> >po[N+2],com;
vector<int>adr[N+2],adc[N+2];
int row[N+2],col[N+2],vis[N+2],now;
void dfs(int node)
{
  vis[node]=1;now=max(now,row[node]);
  for(auto x:adr[node])
  {
    now=max(now,col[x]);com.push_back({node,x});
    for(auto y:adc[x])
      if(!vis[y])dfs(y);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;vector<vector<int> >v(n+3),p(n+3);
  for(int i=1;i<=n;i++)
  {
    v[i].resize(m+3),p[i].resize(m+3);
    for(int j=1;j<=m;j++)cin>>v[i][j];
  }
  compress(v);
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
      po[v[i][j]].push_back({i,j});
  }
  for(int i=1;i<=mx;i++)
  {
    vector<int>tmp,tpm;
    for(auto x:po[i])
    {
      adr[x.first].push_back(x.second);
      adc[x.second].push_back(x.first);
      tmp.push_back(x.first);
      tpm.push_back(x.second);
    }
    for(auto x:tmp)
    {
      if(vis[x])continue;
      com.clear();now=0;dfs(x);now++;
      for(auto x:com)
      {
        p[x.first][x.second]=now;
        row[x.first]=now,col[x.second]=now;
      }
    }
    for(auto x:tmp)
    {
      vis[x]=0;adr[x].clear();
    }
    for(auto x:tpm)adc[x].clear();
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      assert(p[i][j]);
      cout<<p[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}