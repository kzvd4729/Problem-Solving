/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/31/2019 12:46                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 700 KB                               
*  problem: https://codeforces.com/contest/1198/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=50;
int n,qm[N+2][N+2],dp[N+2][N+2][N+2];
string s[N+2];
int dfs(int r,int c1,int c2)
{
  if(r<0||c2<c1)return 0;
  if(dp[r][c1][c2]!=-1)return dp[r][c1][c2];
  int mn=min(r+1,c2-c1+1),ret=1e9;
  for(int i=1;i<=mn;i++)
  {
    int l1=c2-i+1,l2=c2,u1=r-i+1,u2=r;
    int f=0;
    for(int j=u1;j<=u2;j++)
    {
      f+=qm[j][l2];
      if(l1)f-=qm[j][l1-1];
    }
    if(f)f=i;
    ret=min(ret,f+dfs(r,c1,c2-i)+dfs(r-i,c2-i+1,c2));
  }
  return dp[r][c1][c2]=ret;
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
  memset(dp,-1,sizeof(dp));
  cout<<dfs(n-1,0,n-1)<<endl;
   return 0;
}