/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/18/2019 23:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 873 ms                                          memory_used: 44700 KB                             
*  problem: https://codeforces.com/gym/100814/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3,inf=1e9;
int two[N+2],thr[N+2],mt[N+2][N+2],n,m,dp[100+2][100+2][1000+2];
void cal()
{
  for(int i=2;i<=1000;i++)
  {
    int x=i;
    while(x%2==0)x/=2,two[i]++;
    while(x%3==0)x/=3,thr[i]++;
  }
}
int dfs(int i,int j,int c)
{
  if(c<0)return -inf;
  if((i==n&&j==m+1)||(i==n+1&&j==m))return c==0?0:-inf;
  if(i>n||j>m)return -inf;
   if(dp[i][j][c]!=-1)return dp[i][j][c];
  return dp[i][j][c]=two[mt[i][j]]+max(dfs(i+1,j,c-thr[mt[i][j]]),dfs(i,j+1,c-thr[mt[i][j]]));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cal();int t;cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)cin>>mt[i][j];
    }
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=1000;i++)
      dfs(1,1,i);
    int ans=0;
    for(int i=1;i<=1000;i++)
      ans=max(ans,min(i,dp[1][1][i]));
    cout<<ans<<endl;
  }
  return 0;
}