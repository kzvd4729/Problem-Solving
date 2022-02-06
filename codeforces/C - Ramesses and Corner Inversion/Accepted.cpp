/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/12/2019 23:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 2100 KB                              
*  problem: https://codeforces.com/contest/1119/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=500;
int aa[N+2][N+2],bb[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      cin>>aa[i][j];
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      cin>>bb[i][j];
  for(int j=1;j<m;j++)
  {
    vector<int>v;
    for(int i=1;i<=n;i++)
    {
      if(aa[i][j]!=bb[i][j])
        v.push_back(i);
    }
    if(v.size()%2)cout<<"No"<<endl,exit(0);
    for(auto x:v)aa[x][j+1]^=1;
  }
  for(int i=1;i<=n;i++)
  {
    if(aa[i][m]!=bb[i][m])
      cout<<"No"<<endl,exit(0);
  }
  cout<<"Yes"<<endl;
  return 0;
}