/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/05/2018 13:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 97900 KB                             
*  problem: https://codeforces.com/contest/846/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3,inf=2e9;
int mat[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k,q;cin>>n>>m>>k>>q;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      mat[i][j]=inf;
  while(q--)
  {
    int u,v,w;cin>>u>>v>>w;
    mat[u][v]=w;
  }  
    deque<pair<int,int> >dq;
  for(int j=1;j<=m;j++)
  {
    dq.clear();
    for(int i=1;i<=n;i++)
    {
      while(true)
      {
        if(dq.size()==0)break;
        if(dq.back().first<=mat[i][j])
          dq.pop_back();
        else break;
      }
      dq.push_back({mat[i][j],i});
      while(true)
      {
        if(dq.size()==0)break;
        if(dq.front().second<=i-k)
          dq.pop_front();
        else break;
      }
      if(i>=k)mat[i][j]=dq.front().first;
      else mat[i][j]=inf;
    }
  }
    for(int i=1;i<=n;i++)
  {
    dq.clear();
    for(int j=1;j<=m;j++)
    {
      while(true)
      {
        if(dq.size()==0)break;
        if(dq.back().first<=mat[i][j])
          dq.pop_back();
        else break;
      }
      dq.push_back({mat[i][j],j});
      while(true)
      {
        if(dq.size()==0)break;
        if(dq.front().second<=j-k)
          dq.pop_front();
        else break;
      }
      if(j>=k)mat[i][j]=dq.front().first;
      else mat[i][j]=inf;
    }
  }
  int ans=inf;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      ans=min(ans,mat[i][j]);
    }
  }
  if(ans==inf)ans=-1;
  cout<<ans<<endl;
  return 0;
}