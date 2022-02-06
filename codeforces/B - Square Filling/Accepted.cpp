/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/22/2019 20:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1207/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=50;
int ab[N+2][N+2],ba[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      cin>>ab[i][j];
  vector<pair<int,int> >ans;
  for(int i=1;i<n;i++)
  {
    for(int j=1;j<m;j++)
    {
      if(ab[i][j]+ab[i][j+1]+ab[i+1][j]+ab[i+1][j+1]==4)
      {
        ba[i][j]=ba[i][j+1]=ba[i+1][j]=ba[i+1][j+1]=1;
        ans.push_back({i,j});
      }
    }
  }
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      if(ab[i][j]!=ba[i][j])cout<<-1<<endl,exit(0);
  cout<<ans.size()<<"\n";
  for(auto x:ans)
    cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}