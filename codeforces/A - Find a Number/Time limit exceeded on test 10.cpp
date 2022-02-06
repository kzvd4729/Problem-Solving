/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/20/2018 18:04                        
*  solution_verdict: Time limit exceeded on test 10          language: GNU C++14                               
*  run_time: 3000 ms                                         memory_used: 39300 KB                             
*  problem: https://codeforces.com/contest/1070/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
const int inf=1e9;
int d,s,dg,f;vector<int>ans;
int dp[N+N+2][N/10+2],vis[N+N+2][N/10+2];
int dfs(int sm,int md)
{
  if(sm>s)return inf;
  if(sm==s&&md==0)return 0;
  if(dp[sm][md]!=-1)return dp[sm][md];
   dp[sm][md]=inf;
  int i;if(sm)i=0;else i=1;
  for( ;i<=9;i++)
    dp[sm][md]=min(dp[sm][md],1+dfs(sm+i,(md*10+i)%d));
  return dp[sm][md];
}
void path(int st,int sm,int md)
{
  //cout<<dg<<endl;
  if(sm>s)return ;
  if(st>dg)
  {
    if(sm==s&&md==0)
      f=1;
    return ;
  }
  //if(vis[st][md])return ;
  //vis[st][md]=1;
   int i;if(sm)i=0;else i=1;
  for( ;i<=9;i++)
  {
    path(st+1,sm+i,(md*10+i)%d);
    if(f)
    {
      ans.push_back(i);
      return ;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>d>>s;memset(dp,-1,sizeof(dp));
  dg=dfs(0,0);
  if(dg==inf)cout<<-1<<endl,exit(0);
  path(1,0,0);reverse(ans.begin(),ans.end());
  for(auto x:ans)cout<<x;
  cout<<endl;
   return 0;
}