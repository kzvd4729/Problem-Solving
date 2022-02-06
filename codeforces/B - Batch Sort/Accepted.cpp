/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/05/2018 22:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/724/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int mat[22][22],n,m;
bool ck(void)
{
  for(int i=1;i<=n;i++)
  {
    int cnt=0;
    for(int j=1;j<=m;j++)
    {
      if(mat[i][j]!=j)cnt++;
    }
    if(cnt>2)return false;
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>mat[i][j];
    }
  }
  for(int i=1;i<=m;i++)
  {
    for(int j=i;j<=m;j++)
    {
      for(int k=1;k<=n;k++)
      {
        swap(mat[k][i],mat[k][j]);
      }
      if(ck())cout<<"YES"<<endl,exit(0);
      for(int k=1;k<=n;k++)
      {
        swap(mat[k][i],mat[k][j]);
      }
    }
  }
  cout<<"NO"<<endl;
  return 0;
}