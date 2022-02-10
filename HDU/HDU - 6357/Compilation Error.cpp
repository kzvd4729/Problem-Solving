/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-12-29 16:44:43                      
*  solution_verdict: Compilation Error                       language: Java                                    
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HDU-6357
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,fr[N+2][12],bk[N+2][12],dp[N+2][12];
string s;
int dfs(int i,int m)
{
  if(i==n)return 0;
  if(dp[i][m]!=-1)return dp[i][m];
  int ret=0;
  ret=max(ret,dfs(i+1,m));
  if(s[i]-'0'>=m)ret=max(ret,dfs(i+1,s[i]-'0'));

  return dp[i][m]=max(ret,bk[i][m]);
}
int main()
{
  dont compile
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>s;
    for(int i=0;i<=n;i++)
    {
      for(int j=0;j<=10;j++)
        fr[i][j]=0,bk[i][j]=0,dp[i][j]=-1;
    }
    for(int i=0;i<n;i++)
    {
      if(i)
      {
        for(int j=0;j<10;j++)
          fr[i][j]=fr[i-1][j];
      }
      fr[i][s[i]-'0']++;
      for(int j=1;j<10;j++)
        fr[i][j]=max(fr[i][j],fr[i][j-1]);
    }
    for(int i=n-1;i>=0;i--)
    {
      if(i<n-1)
      {
        for(int j=0;j<10;j++)
          bk[i][j]=bk[i+1][j];
      }
      bk[i][s[i]-'0']++;
      for(int j=8;j>=0;j++)
        bk[i][j]=max(bk[i][j],bk[i][j+1]);
    }
    int ans=0;
  }
  return 0;
}