/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/21/2018 17:52                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 156 ms                                          memory_used: 30100 KB                             
*  problem: https://codeforces.com/contest/1070/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
const int inf=1e9;
int d,s,dg,f;
int dp[N+N+N+2][N/10+12];
int dfs(int sm,int md)
{
  if(sm>s)return inf;
  if(sm==s&&md==0)return dp[sm][md]=0;
  if(dp[sm][md]!=-1)return dp[sm][md];
   dp[sm][md]=inf;
  for(int i=9;i>=0;i--)
    dp[sm][md]=min(dp[sm][md],1+dfs(sm+i,(md*10+i)%d));
  return dp[sm][md];
}
void tle()
{
  tle();
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>d>>s;memset(dp,-1,sizeof(dp));
  dg=dfs(0,0);
  if(dg==inf)cout<<-1<<endl,exit(0);
  int md=0,sm=0;
  //if(dg>N)tle();
  while(dg)
  {
    for(int i=0;i<=9;i++)
    {
      if(dp[sm+i][(md*10+i)%d]==dg-1)
      {
        cout<<i;
        dg--;sm+=i;md=(md*10+i)%d;
        break;
      }
    }
  }
  cout<<endl;
  return 0;
}