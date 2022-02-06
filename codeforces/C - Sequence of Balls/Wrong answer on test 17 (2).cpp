/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/05/2018 23:58                        
*  solution_verdict: Wrong answer on test 17                 language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 62700 KB                             
*  problem: https://codeforces.com/contest/67/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=4e3,inf=1e8;
int a,b,c,d;string x,y;
int dp[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>a>>b>>c>>d;cin>>x>>y;
   for(int i=0;i<=N;i++)
    for(int j=0;j<=N;j++)dp[i][j]=inf;
   dp[x.size()][y.size()]=0;
  for(int i=y.size()-1;i>=0;i--)dp[x.size()][i]=(y.size()-i)*a;
  for(int i=x.size()-1;i>=0;i--)dp[i][y.size()]=(x.size()-i)*b;
  for(int i=x.size()-1;i>=0;i--)
  {
    for(int j=y.size()-1;j>=0;j--)
    {
      if(x[i]==y[j])dp[i][j]=min(dp[i][j],dp[i+1][j+1]);
      dp[i][j]=min(dp[i][j],a+dp[i][j+1]);
      dp[i][j]=min(dp[i][j],b+dp[i+1][j]);
      dp[i][j]=min(dp[i][j],c+dp[i+1][j+1]);
      if(i<x.size()-1&&j<y.size()-1&&x[i+1]==y[j])
      {
        for(int k=j+1;k<y.size();k++)
        {
          if(y[k]==x[i])
          {
            dp[i][j]=min(dp[i][j],d+a*(k-j-1)+dp[i+2][k+1]);
            break;
          }
        }
      }
    }
  }
  cout<<dp[0][0]<<endl;
   return 0;
}