/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/13/2020 21:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1438/problem/C
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
#include<sstream> 
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e6;
int a[100+2][100+2],n,m,cl[100+2][100+2];
void dfs(int i,int j,int c)
{
  if(cl[i][j]!=-1)
  {
    if(cl[i][j]!=c)assert(0);
    return ;
  }
  cl[i][j]=c;
  if(j+1<=m)
  {
    if(a[i][j]==a[i][j+1])dfs(i,j+1,c^1);
    else if(abs(a[i][j]-a[i][j+1])==1)dfs(i,j+1,c);
  }
  if(j-1>=1)
  {
    if(a[i][j]==a[i][j-1])dfs(i,j-1,c^1);
    else if(abs(a[i][j]-a[i][j-1])==1)dfs(i,j-1,c);
  }
  if(i+1<=n)
  {
    if(a[i][j]==a[i+1][j])dfs(i+1,j,c^1);
    else if(abs(a[i][j]-a[i+1][j])==1)dfs(i+1,j,c);
  }
  if(i-1>=1)
  {
    if(a[i][j]==a[i-1][j])dfs(i-1,j,c^1);
    else if(abs(a[i][j]-a[i-1][j])==1)dfs(i-1,j,c);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        cin>>a[i][j];cl[i][j]=-1;
      }
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        if(cl[i][j]==-1)dfs(i,j,0);
      }
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
        cout<<a[i][j]+cl[i][j]<<" ";
      cout<<endl;
    }
  }
  return 0;
}