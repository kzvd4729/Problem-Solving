/****************************************************************************************
*  @author: kzvd4729                                         created: 21-04-2020 11:57:23                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 15.4M                                
*  problem: https://www.codechef.com/problems/WALK4
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
int mt[N+2][N+2];long dp[4+2][N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)mt[i][j]=101;
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    mt[u][v]=w;mt[v][u]=w;
    dp[1][u][w]++;dp[1][v][w]++;
  }
  for(int l=2;l<=4;l++)
  {
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        for(int k=1;k<=100;k++)
          dp[l][i][max(k,mt[i][j])]+=dp[l-1][j][k];
      }
    }
  }
  int q;cin>>q;
  while(q--)
  {
    int x;cin>>x;long ans=0;
    for(int i=1;i<=n;i++)
      ans+=dp[4][i][x];
    cout<<ans<<"\n";
  }
  return 0;
}