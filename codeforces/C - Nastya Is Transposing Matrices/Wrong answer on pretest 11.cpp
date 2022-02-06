/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/11/2019 23:39                        
*  solution_verdict: Wrong answer on pretest 11              language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 4800 KB                              
*  problem: https://codeforces.com/contest/1136/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e2;
int n,m,a[N+2][N+2],b[N+2][N+2];
vector<int>u[3],v[3];
void no(void)
{
  cout<<"NO"<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>a[i][j];
      u[(i+j)%2].push_back(a[i][j]);
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>b[i][j];
      v[(i+j)%2].push_back(a[i][j]);
    }
  }
  if(n==1||m==1)
  {
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        if(a[i][j]!=b[i][j])no();
      }
    }
    cout<<"YES"<<endl,exit(0);
  }
  if(a[1][1]!=b[1][1]||a[n][m]!=b[n][m])no();
  sort(u[0].begin(),u[0].end());
  sort(u[1].begin(),u[1].end());
  sort(v[0].begin(),v[0].end());
  sort(v[1].begin(),v[1].end());
  if(u[0]!=v[0])no();
  if(u[1]!=v[1])no();
  cout<<"YES"<<endl;
  return 0;
}