/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/30/2019 13:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 2100 KB                              
*  problem: https://codeforces.com/gym/102001/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e2,inf=1e9;
int mt[N+2][N+2],dg[N+2];
bool cmp(pair<int,int>a,pair<int,int>b)
{
  return dg[a.first]+dg[a.second]>dg[b.first]+dg[b.second];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;if(u>v)swap(u,v);
    mt[u][v]=1;dg[u]++,dg[v]++;
  }
  vector<pair<int,int> >v;
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
      if(!mt[i][j])v.push_back({i,j});
  }
  int mx=inf;
  for(int i=0;i<v.size();i++)
  {
    if(dg[v[i].first]+dg[v[i].second]<mx)
      sort(v.begin()+i,v.end(),cmp);
    mx=min(mx,dg[v[i].first]+dg[v[i].second]);
    dg[v[i].first]++,dg[v[i].second]++;
  }
  cout<<mx<<endl;
  return 0;
}