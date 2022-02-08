/****************************************************************************************
*  @author: kzvd4729                                         created: 05-01-2019 11:14:03                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/JAN19A/problems/DIFNEIGH
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=50;
int n,m,mat[N+2][N+2],col[N*N+2];
map<pair<int,int>,int>mp;
map<int,pair<int,int>>pm;
vector<int>adj[N*N+2];
void make_graph(void)
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      int ii=i-1,jj=j;vector<int>v;
      if(ii>=1&&ii<=n&&jj>=1&&jj<=m)v.push_back(mp[{ii,jj}]);
      ii=i+1,jj=j;
      if(ii>=1&&ii<=n&&jj>=1&&jj<=m)v.push_back(mp[{ii,jj}]);
      ii=i,jj=j+1;
      if(ii>=1&&ii<=n&&jj>=1&&jj<=m)v.push_back(mp[{ii,jj}]);
      ii=i,jj=j-1;
      if(ii>=1&&ii<=n&&jj>=1&&jj<=m)v.push_back(mp[{ii,jj}]);
      for(int i=0;i<v.size();i++)
      {
        for(int j=0;j<v.size();j++)
        {
          if(i==j)continue;
          adj[v[i]].push_back(v[j]);
          //cout<<v[i]<<" "<<v[j]<<endl;
        }
      }
    }
  }
}
void dfs(int node)
{
  if(col[node])return ;
  set<int>st;
  for(auto x:adj[node])
    if(col[x])st.insert(col[x]);
  int cl;
  for(cl=1; ;cl++)
    if(st.find(cl)==st.end())break;
  col[node]=cl;
  for(auto x:adj[node])
    dfs(x);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>m;mp.clear();pm.clear();
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        mp[{i,j}]=++cnt;
        pm[cnt]={i,j};
      }
    }
    for(int i=1;i<=n*m;i++)adj[i].clear();
    make_graph();memset(col,0,sizeof(col));
    for(int i=1;i<=n*m;i++)dfs(i);int mx=0;
    for(int i=1;i<=n*m;i++)
    {
      pair<int,int>p=pm[i];
      mat[p.first][p.second]=col[i];
      mx=max(mx,col[i]);
    }
    cout<<mx<<endl;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        if(j==1)cout<<mat[i][j];
        else cout<<" "<<mat[i][j];
      }
      cout<<endl;
    }
  }
  return 0;
}