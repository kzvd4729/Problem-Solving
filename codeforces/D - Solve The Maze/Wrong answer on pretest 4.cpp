/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/07/2020 21:37                        
*  solution_verdict: Wrong answer on pretest 4               language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1365/problem/D
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=50;
string s[N+2];int n,m,v[N+2][N+2];
bool ok(int i,int j)
{
  return i>=0&&i<n&&j>=0&&j<m;
}
void dfs(int i,int j)
{
  if(v[i][j])return ;
  v[i][j]=1;
  if(ok(i+1,j))
  {
    if(s[i+1][j]!='#')dfs(i+1,j);
  }
  if(ok(i-1,j))
  {
    if(s[i-1][j]!='#')dfs(i-1,j);
  }
  if(ok(i,j+1))
  {
    if(s[i][j+1]!='#')dfs(i,j+1);
  }
  if(ok(i,j-1))
  {
    if(s[i][j-1]!='#')dfs(i,j-1);
  }
}
bool solve()
{
  cin>>n>>m;
  for(int i=0;i<n;i++)cin>>s[i];
   for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(s[i][j]!='B')continue;
      if(ok(i+1,j))
      {
        if(s[i+1][j]=='G')return 0;
        if(s[i+1][j]=='.')s[i+1][j]='#';
      }
      if(ok(i-1,j))
      {
        if(s[i-1][j]=='G')return 0;
        if(s[i-1][j]=='.')s[i-1][j]='#';
      }
      if(ok(i,j+1))
      {
        if(s[i][j+1]=='G')return 0;
        if(s[i][j+1]=='.')s[i][j+1]='#';
      }
      if(ok(i,j-1))
      {
        if(s[i][j-1]=='G')return 0;
        if(s[i][j-1]=='.')s[i][j-1]='#';
      }
    }
  }
  memset(v,0,sizeof v);
  if(s[n-1][m-1]!='#')dfs(n-1,m-1);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(s[i][j]=='G'&&v[i][j]==0)return 0;
    }
  }
  return 1;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    if(solve())cout<<"Yes\n";
    else cout<<"No\n";
  }
  return 0;
}