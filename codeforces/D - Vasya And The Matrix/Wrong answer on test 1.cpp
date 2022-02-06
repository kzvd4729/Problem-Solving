/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/03/2018 22:44                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1016/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m,mat[102][102];
int a[102],b[102],xxr;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    xxr^=a[i];
  }
  for(int i=1;i<=m;i++)
  {
    cin>>b[i];
    xxr^=b[i];
  }
  if(xxr)cout<<"NO"<<endl,exit(0);
   for(int i=2;i<=m;i++)
    mat[1][i]=b[i];
  mat[2][1]=b[1];
   xxr=0;
  for(int j=1;j<=m;j++)
    xxr^=mat[1][j];
  mat[1][1]=xxr^a[1];
   for(int i=2;i<=n;i++)
  {
    xxr=0;
    for(int j=1;j<=m;j++)
      xxr^=mat[j][i];
    mat[i][1]=xxr^a[i];
  }
  cout<<"YES"<<endl;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }
   return 0;
}