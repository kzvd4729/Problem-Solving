/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/06/2018 18:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 5100 KB                              
*  problem: https://codeforces.com/contest/1059/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int n,m,vis[N+2][N+2];
char mat[N+2][N+2];
bool valid(int i,int j)
{
  if(i<1||j<1||i>n||j>m)return false;
  return true;
}
bool one(int i,int j)
{
  if(!valid(i,j))return false;
  if(mat[i][j]=='.')return false;
   i,j++;
  if(!valid(i,j))return false;
  if(mat[i][j]=='.')return false;
   i,j++;
  if(!valid(i,j))return false;
  if(mat[i][j]=='.')return false;
   i++,j;
  if(!valid(i,j))return false;
  if(mat[i][j]=='.')return false;
   i++,j;
  if(!valid(i,j))return false;
  if(mat[i][j]=='.')return false;
   i,j--;
  if(!valid(i,j))return false;
  if(mat[i][j]=='.')return false;
   i,j--;
  if(!valid(i,j))return false;
  if(mat[i][j]=='.')return false;
   i--,j;
  if(!valid(i,j))return false;
  if(mat[i][j]=='.')return false;
    return true;
 }
void visit(int i,int j)
{
  vis[i][j]=1;
  i,j++;
  vis[i][j]=1;
   i,j++;
  vis[i][j]=1;
   i++,j;
  vis[i][j]=1;
   i++,j;
  vis[i][j]=1;
   i,j--;
  vis[i][j]=1;
   i,j--;
  vis[i][j]=1;
   i--,j;
  vis[i][j]=1;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    for(int j=1;j<=m;j++)
      mat[i][j]=s[j-1];
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(one(i,j))
      {
        visit(i,j);
      }
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(mat[i][j]=='#'&&!vis[i][j])cout<<"NO"<<endl,exit(0);
    }
  }
  cout<<"YES"<<endl;
  return 0;
}