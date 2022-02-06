/****************************************************************************************
*  @author: kzvd4729                                         created: May/21/2018 21:17                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 61 ms                                           memory_used: 4000 KB                              
*  problem: https://codeforces.com/contest/985/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;
int n,m,cnt[N+2],f;
char mat[N+2][N+2];
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>s;
    for(int j=1;j<=m;j++)
      mat[i][j]=s[j-1];
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cnt[j]+=mat[i][j]-'0';
    }
  }
  for(int i=1;i<=n;i++)
  {
    int f=0;
    for(int j=1;j<=m;j++)
    {
      cnt[j]-=mat[i][j]-'0';
      if(cnt[j]==0)f=1;
    }
    if(f==0)cout<<"YES"<<endl,exit(0);
    for(int j=1;j<=m;j++)
    {
      cnt[j]+=mat[i][j]-'0';
    }
  }
  cout<<"NO"<<endl;
  return 0;
}