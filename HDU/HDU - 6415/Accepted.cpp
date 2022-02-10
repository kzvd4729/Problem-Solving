/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-16 00:10:02                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 3073                                       memory_used (MB): 156.6                           
*  problem: https://vjudge.net/problem/HDU-6415
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=80;
int n,m,k,dp[N+2][N+2][N*N+4];
int dfs(int i,int j,int c)
{
  if(c>n*m)return 0;
  if(i==n&&j==m&&c==n*m)return 1;
  if(dp[i][j][c]!=-1)return dp[i][j][c];
  int now=0;

  int rm=i*j-c;
  if(rm>0)now=(1LL*now+1LL*rm*dfs(i,j,c+1))%k;
  if(i<n)
  {
    now=(1LL*now+1LL*j*(n-i)*dfs(i+1,j,c+1))%k;
  }
  if(j<m)
  {
    now=(1LL*now+1LL*i*(m-j)*dfs(i,j+1,c+1))%k;
  }
  return dp[i][j][c]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
        for(int c=1;c<=n*m;c++)
          dp[i][j][c]=-1;
    }
    cout<<(1LL*dfs(1,1,1)*(n*m))%k<<"\n";
  }
  return 0;
}