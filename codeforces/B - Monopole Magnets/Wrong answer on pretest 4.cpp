/****************************************************************************************
*  @author: kzvd4729                                         created: May/06/2020 21:07                        
*  solution_verdict: Wrong answer on pretest 4               language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7600 KB                              
*  problem: https://codeforces.com/contest/1344/problem/B
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
#define long long long
using namespace std;
const int N=1e3;
int n,m,vs[N+2][N+2];
string s[N+2];
bool isV(int i,int j)
{
  return i>=1&&i<=n&&j>=1&&j<=m;
}
void dfs(int i,int j)
{
  if(vs[i][j]||s[i][j]=='.')return ;
  vs[i][j]=1;
   if(isV(i+1,j))dfs(i+1,j);
  if(isV(i-1,j))dfs(i-1,j);
  if(isV(i,j+1))dfs(i,j+1);
  if(isV(i,j-1))dfs(i,j-1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>s[i],s[i]="#"+s[i];
   for(int i=1;i<=n;i++)
  {
    int cnt=0,f=0;
    for(int j=1;j<=m;j++)
    {
      if(s[i][j]=='#')cnt++;
      else if(cnt)cnt=0,f++;
    }
    if(cnt)f++;
    if(f>1)cout<<-1<<endl,exit(0);
  }
  for(int j=1;j<=m;j++)
  {
    int cnt=0,f=0;
    for(int i=1;i<=n;i++)
    {
      if(s[i][j]=='#')cnt++;
      else if(cnt)cnt=0,f++;
    }
    if(cnt)f++;
    if(f>1)cout<<-1<<endl,exit(0);
  }
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(vs[i][j]||s[i][j]=='.')continue;
      dfs(i,j);ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}