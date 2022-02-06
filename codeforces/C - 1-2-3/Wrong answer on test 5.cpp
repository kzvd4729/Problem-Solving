/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/25/2018 17:39                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/863/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int a,b,alice[5][5],bob[5][5],vis[5][5],dp[10004][3];
int pt;
long k;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>k>>a>>b;
  for(int i=1;i<=3;i++)
  {
    for(int j=1;j<=3;j++)
    {
      cin>>alice[i][j];
    }
  }
  for(int i=1;i<=3;i++)
  {
    for(int j=1;j<=3;j++)
    {
      cin>>bob[i][j];
    }
  }
  if(a>b)dp[1][1]++;
  if(b>a)dp[1][2]++;
  int i;
  vis[a][b]=1;
  for(i=2;i<=k;i++)
  {
    int aa=alice[a][b];
    b=bob[a][b];
    a=aa;
    if(vis[a][b])
    {
      pt=vis[a][b];
      break;
    }
    vis[a][b]=i;
    dp[i][1]=dp[i-1][1];
    dp[i][2]=dp[i-1][2];
    if(a>b)dp[i][1]++;
    if(b>a)dp[i][2]++;
  }
  --i;
  if(i==k)cout<<dp[i][1]<<" "<<dp[i][2]<<endl,exit(0);
   long aa,bb,cy,mod;
   aa=dp[pt-1][1];
  bb=dp[pt-1][2];
   //cout<<aa<<" "<<bb<<endl;
   k-=(pt-1);
   //cout<<i<<" "<<pt<<endl;
   cy=k/(i-pt+1);
  aa+=(dp[i][1]-dp[pt-1][1])*cy;
  bb+=(dp[i][2]-dp[pt-1][2])*cy;
   mod=k%(i-pt+1);
   aa+=dp[pt+mod-1][1]-dp[pt-1][1];
  bb+=dp[pt+mod-1][2]-dp[pt-1][2];
  cout<<aa<<" "<<bb<<endl;
   return 0;
}