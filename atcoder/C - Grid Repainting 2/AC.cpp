/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-05 18:12:52                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc096/tasks/abc096_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m;
string s;
char mat[55][55];
void check(int i,int j)
{
  if(mat[i+1][j]=='#')return ;
  if(mat[i-1][j]=='#')return ;
  if(mat[i][j+1]=='#')return ;
  if(mat[i][j-1]=='#')return ;
  cout<<"No"<<endl;
  exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   for(int i=0;i<=51;i++)
    for(int j=0;j<=51;j++)
      mat[i][j]='.';
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
      if(mat[i][j]=='#')
        check(i,j);
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}