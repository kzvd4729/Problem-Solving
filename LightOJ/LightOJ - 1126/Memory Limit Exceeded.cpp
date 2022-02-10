/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-13 21:32:17                      
*  solution_verdict: Memory Limit Exceeded                   language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1126
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=500000;
int aa[N+2],n;unordered_map<int,int>dp[52];
int dfs(int i,int df)
{
  if(abs(df)>N/2)return -1e7;
  if(i>n)
  {
    if(df==0)return 0;
    else return -1e7;
  }
  if(dp[i].find(df)!=dp[i].end())return dp[i][df];
  int now=dfs(i+1,df);
  now=max(now,aa[i]+dfs(i+1,df+aa[i]));
  now=max(now,dfs(i+1,df-aa[i]));
  return dp[i][df]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i];
    for(int i=1;i<=n;i++)dp[i].clear();
    int ans=dfs(1,0);
    if(ans<=0)cout<<"Case "<<++tc<<": impossible"<<endl;
    else cout<<"Case "<<++tc<<": "<<dfs(1,0)<<endl;
  }
  return 0;
}