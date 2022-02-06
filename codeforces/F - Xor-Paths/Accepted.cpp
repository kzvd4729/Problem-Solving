/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/18/2018 15:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 639 ms                                          memory_used: 41300 KB                             
*  problem: https://codeforces.com/contest/1006/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,k,mat[22][22];
map<long,long>mp[22];
void dfs(long i,long j,long kk)
{
  if(i>n||j>m)return ;
  if(i+j==(n+m)/2+1)
  {
    mp[i][kk]++;
    return ;
  }
  dfs(i+1,j,kk^mat[i+1][j]);
  dfs(i,j+1,kk^mat[i][j+1]);
}
long dds(long i,long j,long kk)
{
  if(i<1||j<1)return 0;
  if(i+j==(n+m)/2+1)return mp[i][kk];
  return dds(i-1,j,kk^mat[i][j])+dds(i,j-1,kk^mat[i][j]);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m>>k;
  for(long i=1;i<=n;i++)
    for(long j=1;j<=m;j++)
      cin>>mat[i][j];
  dfs(1,1,mat[1][1]);
  cout<<dds(n,m,k)<<endl;
  return 0;
}