/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/31/2019 13:17                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 28800 KB                             
*  problem: https://codeforces.com/contest/1198/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=50;
int n,qm[N+2][N+2],dp[N+2][N+2][N+2][N+2];
string s[N+2];
int dfs(int r1,int r2,int c1,int c2)
{
  if(r2<r1||c2<c1)return 0;
  if(dp[r1][r2][c1][c2]!=-1)return dp[r1][r2][c1][c2];
  int ret=1e9,mx=max(r2-r1+1,c2-c1+1);
  for(int m=1;m<=mx;m++)
  {
    int i=max(r1,r2-m+1),j=max(c1,c2-m+1);
    int f=qm[r2][c2];
    if(i)f-=qm[i-1][c2];if(j)f-=qm[r2][j-1];
    if(i&&j)f+=qm[i-1][j-1];
    if(f)f=m;
    ret=min(ret,f+dfs(i,r2,c1,j-1)+dfs(r1,i-1,j,c2)+dfs(r1,i-1,c1,j-1));
  }
  return dp[r1][r2][c1][c2]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>s[i];
    qm[i][0]=(s[i][0]=='#');
    for(int j=1;j<n;j++)
      qm[i][j]=qm[i][j-1]+(s[i][j]=='#');
  }
  for(int i=1;i<n;i++)
    for(int j=0;j<n;j++)qm[i][j]+=qm[i-1][j];
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0,n-1,0,n-1)<<endl;
   return 0;
}