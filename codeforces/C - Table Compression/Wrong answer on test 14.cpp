/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/24/2020 19:14                        
*  solution_verdict: Wrong answer on test 14                 language: GNU C++14                               
*  run_time: 326 ms                                          memory_used: 40400 KB                             
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
vector<pair<int,int> >po[N+2];
int row[N+2],col[N+2];
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
    int now=0;
    for(auto x:po[i])
    {
      now=max(now,row[x.first]);
      now=max(now,col[x.second]);
    }
    now++;
    for(auto x:po[i])
    {
      p[x.first][x.second]=now;
      row[x.first]=max(row[x.first],now);
      col[x.second]=max(col[x.second],now);
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
      cout<<p[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}